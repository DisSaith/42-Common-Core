/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:32:54 by acohaut           #+#    #+#             */
/*   Updated: 2026/01/16 14:22:49 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	dead_mutex;
	time_t			start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_to_eat;
	int				nbr_philos;
	int				one_is_dead;
}		t_info;

typedef struct s_philo
{
	t_info			*info;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_t		thread;
	int				id;
	int				has_eaten;
	time_t			last_meal;
}		t_philo;

/***************MAIN***************/
void	*routine(void *arg);
void	*monitoring(void *arg);
void	destroy_and_free(t_info *info, t_philo *philo);

/***************INITIALISATION***************/
void	init_info(char *argv[], t_info *info);
void	init_mutex(t_info *info);
void	init_philo(t_philo *philo, t_info *info);

/***************STATE/ACTION***************/
void	is_eating(t_philo *philo);
void	is_dead(t_philo *philo);
void	is_thinking(t_philo *philo);
void	is_sleeping(t_philo *philo);
void	print_message(char *str, t_philo *philo);

/***************UTILS***************/
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_usleep(time_t milliseconds);
time_t	get_time_in_ms(void);
time_t	get_elapsed_time(t_info *info);

/***************CHECKS***************/
int		check_is_dead(t_philo *philo);
int		one_is_dead(t_philo *philo);
int		check_all_eaten(t_philo *philo);
int		check_args(char *argv[], int argc);

/***************ERRORS***************/
void	error_exit(char *msg);
void	error_args(void);
void	error_mutex(char *msg, t_info *info);

#endif
