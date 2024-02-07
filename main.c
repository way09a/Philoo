/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:27:27 by Ahussein          #+#    #+#             */
/*   Updated: 2024/02/07 17:27:28 by Ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_philo *phil)
{
	int	i;

	i = 0;
	phil->info->start_time = get_time();
	while (i < phil->info->num_philo)
	{
		if (pthread_create(&(phil[i].philo_t), NULL,
				routine, &(phil[i])))
			return (1);
		++i;
	}
	check_done_eat_and_die(phil);
	i = 0;
	while (i < phil->info->num_philo)
		pthread_join(phil[i++].philo_t, NULL);
	i = 0;
	while (i < phil->info->num_philo)
		pthread_mutex_destroy(&(phil->info->fork[i++]));
	pthread_mutex_destroy(&(phil->info->printig));
	pthread_mutex_destroy(&(phil->info->eating));
	pthread_mutex_destroy(&(phil->info->die));
	pthread_mutex_destroy(&(phil->info->count_eat));
	return (0);
}

int	main(int ac, char **av)
{
	t_philo		philo;
	t_info		info;

	if (!parser(ac, av))
		return (0);
	info_init(&philo, &info, ac, av);
	return (0);
}
