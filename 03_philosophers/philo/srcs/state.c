/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:22:49 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/16 17:59:50 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo);
	if (philo->info->nbr_philos == 1)
	{
		ft_usleep(philo->info->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo);
	print_message("is eating", philo);
	pthread_mutex_lock(&philo->info->meal_mutex);
	philo->last_meal = get_time_in_ms();
	philo->has_eaten++;
	pthread_mutex_unlock(&philo->info->meal_mutex);
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	is_sleeping(t_philo *philo)
{	
	print_message("is sleeping", philo);
	ft_usleep(philo->info->time_to_sleep);
}

void	is_thinking(t_philo *philo)
{
	print_message("is thinking", philo);
}

void	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->dead_mutex);
	if (philo->info->one_is_dead)
	{
		pthread_mutex_unlock(&philo->info->dead_mutex);
		return ;
	}
	philo->info->one_is_dead = 1;
	pthread_mutex_unlock(&philo->info->dead_mutex);
	pthread_mutex_lock(&philo->info->write_mutex);
	printf("%ld %d died\n", get_elapsed_time(philo->info), philo->id);
	pthread_mutex_unlock(&philo->info->write_mutex);
}

void	print_message(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->info->write_mutex);
	if (!philo->info->one_is_dead)
		printf("%ld %d %s\n",
			get_elapsed_time(philo->info), philo->id, str);
	pthread_mutex_unlock(&philo->info->write_mutex);
}
