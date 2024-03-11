/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:48:59 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/11 15:45:01 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	set_counter(t_data *data);

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->data_sem);
		if (philo->data->life_state == DEAD || philo->data->stop)
		{
			sem_post(philo->data->data_sem);
			return (0);
		}
		sem_post(philo->data->data_sem);
		if (take_forks(philo))
			continue ;
		eat_and_sleep(philo);
		think(philo);
	}
	return (0);
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
			ft_routine(data->philos[i]);
			exit(0);
		}
		i++;
		usleep(100);
	}
}

void	wait_for_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		waitpid(data->philos[i].pid, 0, 0);
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
