/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:34:44 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/16 18:06:02 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!one_is_dead(philo))
	{
		if (philo->info->meals_to_eat > 0
			&& philo->has_eaten >= philo->info->meals_to_eat)
			break ;
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}

void	*monitoring(void *arg)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!one_is_dead(philo))
	{
		i = 0;
		if (philo->info->meals_to_eat > 0 && check_all_eaten(philo))
			break ;
		while (i < philo->info->nbr_philos)
		{
			if (check_is_dead(&philo[i]))
			{
				is_dead(&philo[i]);
				break ;
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

void	destroy_and_free(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->nbr_philos)
	{
		pthread_mutex_destroy(&info->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&info->write_mutex);
	pthread_mutex_destroy(&info->dead_mutex);
	pthread_mutex_destroy(&info->meal_mutex);
	free(info->fork);
	free(philo);
}

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	t_info	info;
	int		i;

	check_args(argv, argc);
	init_info(argv, &info);
	philo = malloc(sizeof(t_philo) * (info.nbr_philos + 1));
	if (!philo)
		error_exit("problem alloc tab of struct philo");
	init_philo(philo, &info);
	i = 0;
	while (i <= info.nbr_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	destroy_and_free(&info, philo);
	return (0);
}
