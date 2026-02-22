/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:03:00 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 18:03:02 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int	nb_read = 1;
	char	tab[256];
	int	fd = open("text.txt", O_RDWR);
	if (fd == -1)
		return (1);
	
	ft_putendl_fd("Bien le bonjour compagnie", fd);
	lseek(fd, 0, SEEK_SET);
	while (nb_read > 0)
	{
		nb_read = read(fd, tab, 256);
		if (nb_read == -1)
			return (1);
		tab[nb_read] = '\0';
		write(1, tab, nb_read);
	}
	close(fd);
	return (0);
}*/
