/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:46:54 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/17 14:35:49 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*take_line(char *file)
{
	char	*line;
	size_t	size;
	size_t	i;

	if (!file)
		return (NULL);
	size = 0;
	i = 0;
	while (file[size] && file[size] != '\n')
		size++;
	line = malloc(sizeof(char) * (size + 2));
	if (!line)
		return (NULL);
	while (file[i] && file[i] != '\n')
	{
		line[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *file)
{
	char	*buffer;
	ssize_t	nb_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nb_read = 1;
	while (!(ft_strchr(file, '\n')) && nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(buffer);
			free(file);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		file = ft_strjoin(file, buffer);
	}
	free(buffer);
	return (file);
}

char	*sup_line_static(char *file)
{
	char	*nw_file;
	size_t	i;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	nw_file = ft_strdup(&file[i + 1]);
	free(file);
	return (nw_file);
}

char	*get_next_line(int fd)
{
	static char	*file[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	file[fd] = read_file(fd, file[fd]);
	if (!file[fd])
		return (NULL);
	if (file[fd][0] == '\0')
	{
		free(file[fd]);
		file[fd] = NULL;
		return (NULL);
	}
	line = take_line(file[fd]);
	file[fd] = sup_line_static(file[fd]);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int	fd1 = open("text1.txt", O_RDONLY);
	int	fd2 = open("text2.txt", O_RDONLY);
	char	*str1;
	char	*str2;
	printf("fd1 = %s", str1 = get_next_line(fd1));
	free(str1);
	printf("fd2= %s", str2 = get_next_line(fd2));
	free(str2);
	printf("fd1 = %s", str1 = get_next_line(fd1));
	free(str1);
	printf("fd2 = %s", str2 = get_next_line(fd2));
	free(str2);
	close (fd1);
	close (fd2);
	return (0);
}*/
