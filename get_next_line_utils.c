/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillan- <pmillan-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:39:56 by pmillan-          #+#    #+#             */
/*   Updated: 2022/06/27 15:51:09 by pmillan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	contains_line_break(char *buf)
{
	int	i;

	i = 0;
	if (buf == NULL)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_copystr(char *s)
{
	char	*scopy;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	scopy = malloc(ft_strlen(s) + 1);
	while (s[i])
	{
		scopy[i] = s[i];
		i++;
	}
	scopy[i] = '\0';
	return (scopy);
}

char	*ft_strjoin(char *store, char *buf)
{
	char	*str;
	int		i;
	int		storelen;

	if (*buf == 0)
		return (store);
	if (!store)
		return (ft_copystr(buf));
	storelen = ft_strlen(store);
	i = -1;
	str = (char *)malloc(sizeof(char) * (storelen + ft_strlen(buf) + 1));
	if (str == NULL)
		return (NULL);
	while (store[++i])
		str[i] = store[i];
	while (buf[i - storelen])
	{
		str[i] = buf[i - storelen];
		i++;
	}
	str[i] = '\0';
	free(store);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
	{
		len++;
	}
	return (len);
}
