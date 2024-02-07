/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:28:18 by Ahussein          #+#    #+#             */
/*   Updated: 2024/02/07 17:28:19 by Ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_info *info)
{
	int	i;

	info->fork = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_init(&info->fork[i++], NULL);
	}
	pthread_mutex_init(&info->eating, NULL);
	pthread_mutex_init(&info->die, NULL);
	pthread_mutex_init(&info->printig, NULL);
	pthread_mutex_init(&info->count_eat, NULL);
}

void	philo_init(t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		philo[i].info = info;
		philo[i].ate = 0;
		philo[i].id = i;
		philo[i].info->fork_status[i] = 0;
		philo[i].info->sig[i] = -1;
		philo[i].lfork = i;
		philo[i].rfork = (i + 1) % info->num_philo;
		philo[i].last_ate = get_time();
	}
}

void	info_init(t_philo *philo, t_info *info, int ac, char **av)//
{
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	info = malloc(sizeof(t_info));
	info->num_philo = ft_atoi(av[1]);
	info->fork_status = malloc(sizeof(int) * info->num_philo);
	info->sig = malloc(sizeof(int) * info->num_philo);
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	info->done_eat = 0;
	info->died = 0;
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = -1;
	init_mutex(info);
	philo_init(info, philo);
	create_philo(philo);
	free(philo);
	free(info->fork);
	free(info->fork_status);
	free(info->sig);
	free(info);
}
