/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:03:08 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 18:03:09 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	tab[12];
	long	nbr;
	size_t	i;

	nbr = (long)n;
	i = 0;
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		tab[i] = nbr % 10 + '0';
		nbr /= 10;
		i++;
	}
	while (i-- > 0)
		write(fd, &tab[i], 1);
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
	
	ft_putnbr_fd(-2147483648, fd);
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
