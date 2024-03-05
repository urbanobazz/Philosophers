/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:42:39 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/05 14:04:26 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_all_life_state(t_data *data);

void	monitor_philosophers(t_data *data)
{
	while (1)
	{
		usleep(data->time_to_eat);
		if (check_all_life_state(data) == DEAD)
			return ;
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
			printf("---------philo[%d] Meal: %ld Time: %ld Res: %ld-----------\n", data->philos[i].id, data->philos[i].last_meal, time, time - data->philos[i].last_meal);
			pthread_mutex_lock(&data->data_mutex);
			print_status(&data->philos[i], "died");
			data->life_state = DEAD;
			pthread_mutex_unlock(&data->data_mutex);
			return (DEAD);
		}
		i++;
	}
	return (ALIVE);
}
