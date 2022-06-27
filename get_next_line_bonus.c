/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillan- <pmillan-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:29:41 by pmillan-          #+#    #+#             */
/*   Updated: 2022/06/27 15:55:49 by pmillan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// cuando acaba esta función lo que obtenemos es store que contiene la linea 
// que queremos y el resto de cosas que haya leído
char	*read_until_lb(int fd, char *store)
{
	int			read_int;
	char		*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	read_int = 1;
	while (!contains_line_break(store) && read_int > 0)
	{
		read_int = read(fd, buf, BUFFER_SIZE);
		if (read_int == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_int] = '\0';
		store = ft_strjoin(store, buf);
	}
	free(buf);
	return (store);
}

// cuando acaba esta función obtenemos la línea deseada incluyendo
// el salto de línea. 
char	*ft_getline(char *store)
{
	char		*line;
	size_t		i;

	if (store == NULL || *store == 0)
		return (NULL);
	i = 0;
	while (store[i] != '\n' && store[i] != '\0')
		i++;
	if (store[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (store[i] != '\n' && store[i] != '\0')
	{
		line[i] = store[i];
		i++;
	}
	line[i] = store[i];
	line[++i] = 0;
	return (line);
}

// función auxiliar para copiar la parte que nos interesa de store.
char	*ft_copystore(char *store, char *new_store, size_t *i)
{
	size_t	j;

	j = 0;
	while (store[++(*i)] != '\0')
	{	
		new_store[j] = store[*i];
		j++;
	}
	new_store[j] = '\0';
	return (new_store);
}

char	*ft_getstore(char *store)
{
	size_t	len;
	size_t	i;
	char	*new_store;

	if (store == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(store);
	while (store[i] != '\0' && store[i] != '\n')
		i++;
	if (store[i] == '\0')
	{
		free (store);
		return (NULL);
	}
	new_store = malloc(sizeof(char) * (len - i));
	new_store = ft_copystore(store, new_store, &i);
	free (store);
	return (new_store);
}

// función principal que nos devuelve la siguiente línea
// en un archivo cada vez que la invocamos.
char	*get_next_line(int fd)
{
	char		*line;
	static char	*store[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	store[fd] = read_until_lb(fd, store[fd]);
	line = ft_getline(store[fd]);
	store[fd] = ft_getstore(store[fd]);
	if (store[fd] == NULL)
		free(store[fd]);
	return (line);
}

/*
int	main(void)
{
	char *str;
	int	i, j;
	int		fd[3];

	fd[0] = open("41_with_nl.txt", O_RDONLY);
	fd[1] = open("42_with_nl", O_RDONLY);
	fd[2] = open("43_with_nl", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			str = get_next_line(fd[i]);
			free(str);
			j++;
		}
		i++;
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	//system("leaks a.out");
}
*/