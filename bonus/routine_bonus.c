/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:48:59 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/14 10:26:20 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void		set_counter(t_data *data);

int	routine(t_philo *philo)
{
	while (1)
	{
		if (!end_simulation(philo))
			if (take_forks(philo))
				return (DEAD);
		if (!end_simulation(philo))
			eat_and_sleep(philo);
		if (!end_simulation(philo))
			think(philo);
		else
		{
			if (end_simulation(philo) == 1)
				return (DEAD);
			if (end_simulation(philo) == 2)
				return (ALIVE);
		}
	}
	return (ALIVE);
}

int	end_simulation(t_philo *philo)
{
	long	time;
	int		i;

	i = 0;
	time = get_time();
	if (time - philo->last_meal > philo->time_to_die)
	{
		print_status(philo, "died");
		philo->life_state = DEAD;
		return (1);
	}
	if (philo->eaten_meals == philo->data->meals_count)
		return (2);
	else
		return (0);
}

void	create_philos(t_data *data)
{
	int	i;
	int	exit_code;

	i = 0;
	exit_code = 0;
	data->starting_time = get_time();
	set_counter(data);
	while (i < data->philo_count)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid == 0)
		{
			exit_code = routine(&data->philos[i]);
			if (exit_code == DEAD)
				sem_wait(data->print_sem);
			exit (exit_code);
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
