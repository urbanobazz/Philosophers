/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:42:39 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/05 18:19:54 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_all_life_state(t_data *data);
static int	check_meals_eaten(t_data *data);

void	monitor_philosophers(t_data *data)
{
	while (1)
	{
		usleep(data->time_to_eat);
		if (check_all_life_state(data) == DEAD)
			return ;
		if (check_meals_eaten(data))
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
			printf("---philo[%d] Meal: %ld Time: %ld Passed: %ld-----------\n", data->philos[i].id, data->philos[i].last_meal, time, time - data->philos[i].last_meal);
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

static int	check_meals_eaten(t_data *data)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (i < data->philo_count)
	{
		if (data->philos[i].eaten_meals == data->meals_count)
			check++;
		i++;
	}
	if (check == data->philo_count)
		return (data->stop = 1, 1);
	return (0);
}
