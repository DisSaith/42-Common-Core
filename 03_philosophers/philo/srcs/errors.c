/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:29:10 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/16 13:28:56 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	error_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(0);
}

void	error_args(void)
{
	write(2, "Error\n", 6);
	write(2, "Usage: ./philo [nbr_philos] [time_to_die] [time_to_eat]", 55);
	write(2, " [time_to_sleep] + (optional) [meals_to_eat]\n", 45);
	write(2, "Example: ./philo 3 600 100 100 4\n", 33);
	write(2, "times -> in ms | nbr_philos -> 1 to 200\n", 39);
	exit(0);
}

void	error_mutex(char *msg, t_info *info)
{
	int	i;

	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	i = 0;
	while (i < info->nbr_philos)
	{
		pthread_mutex_destroy(&info->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&info->write_mutex);
	pthread_mutex_destroy(&info->dead_mutex);
	pthread_mutex_destroy(&info->meal_mutex);
	if (info->fork)
		free(info->fork);
	exit(0);
}
