/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:55:58 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/06 17:11:28 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_counter(t_data *data);

static void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->data->data_mutex);
		if (philo->data->life_state == DEAD || philo->data->stop)
		{
			pthread_mutex_unlock(&philo->data->data_mutex);
			return (0);
		}
		pthread_mutex_unlock(&philo->data->data_mutex);
		take_forks(philo);
		eat_and_sleep(philo);
		think(philo);
	}
	return (0);
}

void	init_philosophers(t_data *data)
{
	int i;

	i = 0;
	data->starting_time = get_time();
	set_counter(data);
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, routine, &data->philos[i]) != 0)
			ft_exit(data, "Thread init error\n", 1);
		i++;
	}
}

void	join_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
			ft_exit(data, "Thread join error\n", 1);
		i++;
	}
}

void	set_counter(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].last_meal = data->starting_time;
		i++;
	}
}
