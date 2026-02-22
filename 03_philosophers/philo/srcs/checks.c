/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:15:26 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/16 18:05:55 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_is_dead(t_philo *philo)
{
	time_t	last;

	pthread_mutex_lock(&philo->info->meal_mutex);
	last = philo->last_meal;
	pthread_mutex_unlock(&philo->info->meal_mutex);
	if (get_time_in_ms() - last > philo->info->time_to_die)
		return (1);
	return (0);
}

int	one_is_dead(t_philo *philo)
{
	int	is_dead;

	pthread_mutex_lock(&philo->info->dead_mutex);
	is_dead = philo->info->one_is_dead;
	pthread_mutex_unlock(&philo->info->dead_mutex);
	if (is_dead == 1)
		return (1);
	return (0);
}

int	check_all_eaten(t_philo *philo)
{
	int	i;
	int	count;

	pthread_mutex_lock(&philo->info->meal_mutex);
	count = 0;
	i = 0;
	while (i < philo->info->nbr_philos)
	{
		if (philo[i].has_eaten >= philo->info->meals_to_eat)
			count++;
		i++;
	}
	pthread_mutex_unlock(&philo->info->meal_mutex);
	if (count == philo->info->nbr_philos)
	{
		pthread_mutex_lock(&philo->info->dead_mutex);
		philo->info->one_is_dead = 1;
		pthread_mutex_unlock(&philo->info->dead_mutex);
		return (1);
	}
	return (0);
}

int	check_args(char *argv[], int argc)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		error_args();
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				error_args();
			j++;
		}
		i++;
	}
	return (1);
}
