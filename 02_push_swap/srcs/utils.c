/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:20:30 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/04 10:20:32 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	atoi_push_swap(char *str)
{
	long	nb;
	int		i;
	int		sign;

	if (!str)
		return ((long)0);
	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i])
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return (nb * sign);
}

int	strlength(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	display_operation(char *str)
{
	write(1, str, strlength(str));
	write(1, "\n", 1);
}

int		display_error(int argc, char *argv[], int error)
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	if (!error)
		return (1);
	write(2, "Error\n", 6);
	return (0);
}
