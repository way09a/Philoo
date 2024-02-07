/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:28:23 by Ahussein          #+#    #+#             */
/*   Updated: 2024/02/07 17:28:24 by Ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo) //
{
	t_philo	*phil;

	phil = (t_philo *)philo;
	if (phil->id % 2)
		usleep(2000);
	while (!ft_check_died(phil))
	{
		philo_eat(phil);
		if (phil->info->must_eat > 0 && phil->ate == phil->info->must_eat)
			break ;
		print(phil, phil->id, "is sleeping");
		time_pause(phil, phil->info->time_sleep);
		print(phil, phil->id, "is thinking");
	}
	return (NULL);
}

void	print(t_philo *philo, int id, char *is_doing)
{
	pthread_mutex_lock(&(philo->info->printig));
	if (!ft_check_died(philo))
	{
		printf("%lli %i %s\n", get_time() - philo->info->start_time,
			id + 1, is_doing);
	}
	pthread_mutex_unlock(&(philo->info->printig));
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	time_pause(t_philo *philo, int time_pause)
{
	long long	time;

	time = get_time();
	while (!ft_check_died(philo))
	{
		if (get_time() - time >= time_pause)
			break ;
		usleep(500);
	}
}
