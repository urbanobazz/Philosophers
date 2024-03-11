/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:48:59 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/11 19:46:33 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	set_counter(t_data *data);

void	routine(t_philo *philo)
{
	pthread_t	life_state;

	pthread_create(&life_state, NULL, monitor_philosophers, philo);
	pthread_detach(life_state);
	while (1)
	{
		sem_wait(philo->data->data_sem);
		if (philo->life_state == DEAD)
		{
			sem_post(philo->data->data_sem);
			break ;
		}
		sem_post(philo->data->data_sem);
		if (take_forks(philo))
			continue ;
		eat_and_sleep(philo);
		think(philo);
	}
}

void	create_philos(t_data *data)
{
	int	i;

	i = 0;
	data->starting_time = get_time();
	set_counter(data);
	while (i < data->philo_count)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid == 0)
		{
			routine(&data->philos[i]);
			exit(0);
		}
		i++;
	}
}

void	set_counter(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].last_meal = data->starting_time;
		i++;
	}
}
