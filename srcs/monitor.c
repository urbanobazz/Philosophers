/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:42:39 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/02 14:24:42 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_all_life_state(t_data *data);

void	monitor_philosophers(t_data *data)
{
	while (1)
	{
		if (check_all_life_state(data) == DEAD)
			return ;
		usleep(1000);
	}
}

static int	check_all_life_state(t_data *data)
{
	int i;
	long	time;

	i = 0;
	while (i < data->philo_count)
	{
		time = get_time();
		if (time - data->philos[i].last_meal > data->time_to_die)
		{
			pthread_mutex_lock(&data->data_mutex);
			printf("%ld %ld died\n", time - data->starting_time, data->philos[i].id);
			data->life_state = DEAD;
			pthread_mutex_unlock(&data->data_mutex);
			return (DEAD);
		}
	}
	return (ALIVE);
}
