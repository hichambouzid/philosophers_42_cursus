/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:39:27 by hibouzid          #+#    #+#             */
/*   Updated: 2024/06/11 16:13:03 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_help(char *str)
{
	int	i;
	int	j;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	j = i;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	if (j == i || ft_strlen(str) != j || j - i > 10)
		return (-1);
	return (0);
}

int	ft_parse_data(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_help(av[i]))
			return (-1);
		i++;
	}
	return (0);
}

t_philo	*ft_parse_args(int ac, t_philo *data)
{
	if (data->n_philo <= 0 || data->t_die <= 0 || data->t_eat <= 0
		|| data->t_sleep <= 0)
	{
		free(data);
		return (NULL);
	}
	if (data->t_sleep < 60000 || data->t_die < 60000 || data->t_eat < 60000)
	{
		free(data);
		return (NULL);
	}
	if (ac == 6 && data->n_repeat <= 0)
	{
		free(data);
		return (NULL);
	}
	if (ac < 6)
		data->n_repeat = 0;
	return (data);
}

t_philo	*fill_struct(int ac, char **av)
{
	t_philo	*data;

	if (ac < 5 || ac > 6 || ft_parse_data(ac, av))
		return (NULL);
	data = malloc(sizeof(t_philo));
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]) * 1000;
	data->t_eat = ft_atoi(av[3]) * 1000;
	data->t_sleep = ft_atoi(av[4]) * 1000;
	if (ac == 6)
		data->n_repeat = ft_atoi(av[5]);
	return (ft_parse_args(ac, data));
}
