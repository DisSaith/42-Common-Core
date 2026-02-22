/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:42:40 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/17 14:38:17 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_struct_gnl(t_gnl *gnl)
{
	gnl->line = NULL;
	gnl->tmp = NULL;
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1];
	t_gnl		gnl;

	init_struct_gnl(&gnl);
	while (1)
	{
		if (ft_strchr_gnl(b, '\n', &gnl.tmp) != NULL)
		{
			if (!ft_strjoin_gnl(&gnl.line, b, gnl.tmp - b + 1))
				return (free(gnl.line), NULL);
			ft_memmove(b, gnl.tmp + 1, ft_strlen(gnl.tmp + 1) + 1);
			return (gnl.line);
		}
		if (!ft_strjoin_gnl(&gnl.line, b, ft_strlen(b)))
			return (free(gnl.line), NULL);
		gnl.readed = read(fd, b, BUFFER_SIZE);
		if (gnl.readed <= 0)
		{
			b[0] = '\0';
			if (gnl.line && *gnl.line)
				return (gnl.line);
			return (free(gnl.line), NULL);
		}
		b[gnl.readed] = '\0';
	}
}
/*
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int	fd = open("text1.txt", O_RDONLY);
	char	*str;
	int	i;

	i = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("line[%d] = %s", i, str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	printf("line[%d] = %s", i, str);
	free(str);
	close (fd);
	return (0);
}*/
