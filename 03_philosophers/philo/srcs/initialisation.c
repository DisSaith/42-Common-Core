/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:03:06 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/16 14:11:22 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_philo(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_philos)
	{
		philo[i].has_eaten = 0;
		philo[i].last_meal = get_time_in_ms();
		philo[i].id = i + 1;
		philo[i].right_fork = &info->fork[i];
		if (info->nbr_philos > 1)
			philo[i].left_fork = &info->fork[(i + 1) % info->nbr_philos];
		else
			philo[i].left_fork = NULL;
		philo[i].info = info;
		if ((pthread_create(&philo[i].thread, NULL, routine, &philo[i])) != 0)
			error_exit("problem in creation of a thread");
		i++;
	}
	if ((pthread_create(&philo[i].thread, NULL, monitoring, philo)) != 0)
		error_exit("problem in creation of monitor");
}

void	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_philos)
	{
		if ((pthread_mutex_init(&info->fork[i], NULL)) != 0)
			error_mutex("problem init mutex", info);
		i++;
	}
	if ((pthread_mutex_init(&info->write_mutex, NULL)) != 0)
		error_mutex("problem init mutex", info);
	if ((pthread_mutex_init(&info->meal_mutex, NULL)) != 0)
		error_mutex("problem init mutex", info);
	if ((pthread_mutex_init(&info->dead_mutex, NULL)) != 0)
		error_mutex("problem init mutex", info);
}

void	init_info(char *argv[], t_info *info)
{
	info->nbr_philos = ft_atoi(argv[1]);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nbr_philos);
	if (!info->fork)
		error_exit("problem alloc tab of mutex");
	init_mutex(info);
	info->one_is_dead = 0;
	info->start_time = get_time_in_ms();
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->meals_to_eat = ft_atoi(argv[5]);
	else
		info->meals_to_eat = 0;
}
