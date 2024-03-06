/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:16:41 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/06 17:11:41 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philos_init(t_data *data);
static void	forks_init(t_data *data);

t_data	*data_init(int argc, char **argv)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		ft_exit(NULL, "Malloc error\n", 1);
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_count = ft_atoi(argv[5]);
	else
		data->meals_count = -1;
	data->starting_time = 0;
	data->stop = 0;
	data->life_state = ALIVE;
	pthread_mutex_init(&data->data_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	forks_init(data);
	philos_init(data);
	return (data);
}

static void	philos_init(t_data *data)
{
	int i;

	i = 0;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		ft_exit(data, "Malloc error(2)\n", 1);
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->time_to_die;
		data->philos[i].time_to_eat = data->time_to_eat;
		data->philos[i].time_to_sleep = data->time_to_sleep;
		data->philos[i].last_meal = 0;
		data->philos[i].eaten_meals = 0;
		data->philos[i].thread_id = 0;
		data->philos[i].right_fork = &data->forks[i];
		data->philos[i].left_fork = &data->forks[(i + 1) % data->philo_count];
		data->philos[i].data = data;
		i++;
	}
}

static void	forks_init(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		ft_exit(data, "Malloc error(3)\n", 1);
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			ft_exit(data, "Mutex init error(fork)\n", 1);
		i++;
	}
}
