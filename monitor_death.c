/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:28:04 by Ahussein          #+#    #+#             */
/*   Updated: 2024/02/07 17:28:05 by Ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death(t_philo *philo) //all/
{
	pthread_mutex_lock(&(philo->info->die));
	philo->info->died = 1;
	pthread_mutex_unlock(&(philo->info->die));
}

int	ft_check_died(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->die));
	if (philo->info->died)
	{
		pthread_mutex_unlock(&(philo->info->die));
		return (1);
	}
	pthread_mutex_unlock(&(philo->info->die));
	return (0);
}

int	check_done_eat(t_philo *philo)
{
	int			i;
	int			j;
	int			ate;

	i = 0;
	j = 0;
	while (i < philo->info->num_philo)
	{
		pthread_mutex_lock(&(philo->info->count_eat));
		ate = philo[i].ate;
		pthread_mutex_unlock(&(philo->info->count_eat));
		if (ate == philo->info->must_eat)
		{
			j++;
		}
		if (j == philo->info->num_philo)
			return (1);
		i++;
	}
	return (0);
}

int	check_death(t_philo *philo)
{
	int			i;
	long long	time;

	i = 0;
	while (i < philo->info->num_philo)
	{
		pthread_mutex_lock(&(philo->info->eating));
		time = philo[i].last_ate;
		pthread_mutex_unlock(&(philo->info->eating));
		if (get_time() - time >= philo->info->time_die)
		{
			print(philo, i, "died");
			death(philo);
		}
		if (ft_check_died(philo))
			return (1);
		i++;
	}
	return (0);
}

void	check_done_eat_and_die(t_philo *phil)
{
	while (1)
	{
		usleep(200);
		if (check_death(phil) || check_done_eat(phil))
			break ;
	}
}
