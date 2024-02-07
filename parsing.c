/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:28:09 by Ahussein          #+#    #+#             */
/*   Updated: 2024/02/07 17:28:10 by Ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	while (!ft_isdigit(str[i++]))
		return (0);
	i = 0;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
		if ((res > 2147483647 && sign == 1))
			return (-1);
	}
	return (res * sign);
}

int	is_char(int ac, char **av)
{
	int			i;
	int			j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parser(int ac, char **av)
{
	if (ac > 6 || ac < 5)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	if (is_char(ac, av) == 0)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	if (ft_atoi(av[1]) > 200
		|| ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60
		|| ft_atoi(av[4]) < 60 || ft_atoi(av[1]) < 1)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	else if (ft_atoi(av[ac - 1]) <= 0 && ac == 6)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	return (1);
}
