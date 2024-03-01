/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:16:41 by ubazzane          #+#    #+#             */
/*   Updated: 2024/02/29 20:58:06 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	data_init(t_data *data, int argc, char **argv)
{
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		exit_error(NULL, "Malloc error\n");
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_count = ft_atoi(argv[5]);
	else
		data->meals_count = -1;
	data->starting_time = 0;
	forks_init(data);
	philos_init(data);
}

void	*philos_init(t_data *data)
{
	int i;

	i = 0;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		exit_error(data, "Malloc error(2)\n");
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = 0;
		data->philos[i].eaten_meals = 0;
		data->philos[i].right_fork = &data->forks[i];
		data->philos[i].left_fork = &data->forks[(i + 1) % data->philo_count];
		i++;
	}
}

void	forks_init(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		exit_error(data, "Malloc error(3)\n");
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			exit_error(data, "Mutex init error\n");
		i++;
	}
}
