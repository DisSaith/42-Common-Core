/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:46:35 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/17 14:37:35 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	ssize_t	readed;
	char	*line;
	char	*tmp;
}			t_gnl;

size_t	ft_strlen(const char *s);

int		ft_strjoin_gnl(char **s1, char *s2, size_t size2);

void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);

char	*ft_strchr_gnl(char *s, char c, char **tmp);
char	*get_next_line(int fd);

#endif
