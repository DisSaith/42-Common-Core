/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:46:58 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/17 14:35:23 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# define FD_MAX 1024

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*take_line(char *file);
char	*read_file(int fd, char *file);
char	*sup_line_static(char *file);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);

size_t	ft_strlen(char *s);

#endif
