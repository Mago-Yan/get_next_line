/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillan- <pmillan-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:37:39 by pmillan-          #+#    #+#             */
/*   Updated: 2022/06/01 14:01:07 by pmillan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>

char	*get_next_line(int fd);
int		contains_line_break(char *buf);
char	*ft_copystr(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*read_until_lb(int fd, char *store);
char	*ft_getline(char *store);
char	*ft_copystore(char *store, char *new_store, size_t *i);
char	*ft_getstore(char *store);

#endif
