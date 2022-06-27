/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillan- <pmillan-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:29:41 by pmillan-          #+#    #+#             */
/*   Updated: 2022/06/27 15:56:17 by pmillan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (!new_store)
		return (NULL);
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
	static char	*store;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	store = read_until_lb(fd, store);
	line = ft_getline(store);
	store = ft_getstore(store);
	if (store == NULL)
		free(store);
	return (line);
}
/*
int	main(void)
{
	char *str;
	int	i;
	int		fd;

	fd = open("test1.txt", O_RDONLY);
	i = 0;
	while (i < 8)
	{
		str = get_next_line(fd);
		free(str);
		i++;
	}
	close(fd);
	//system("leaks a.out");
}
*/