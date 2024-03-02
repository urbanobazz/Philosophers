/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:42:39 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/02 13:00:46 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	life_check_all(t_data *data);

void	monitor_philosophers(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->data_mutex);
		if (life_check_all(data) == DEAD)
		{
			pthread_mutex_unlock(&data->data_mutex);
			return ;
		}
		pthread_mutex_unlock(&data->data_mutex);
		usleep(1000);
	}
}

static int	life_check_all(t_data *data)
{
	int i;

	i = 0;

	while (i < data->philo_count)
	{
		if (life_state(&data->philos[i]) == DEAD)
		{
			pthread_mutex_lock(&data->data_mutex);
			data->life_state = DEAD;
			pthread_mutex_unlock(&data->data_mutex);
			return (DEAD);
		}
	}
	return (ALIVE);
}
