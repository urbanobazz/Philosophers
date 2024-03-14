/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:02:27 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/14 14:23:22 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	pass_time(t_philo *philo, int time);

int	take_forks(t_philo *philo)
{
	if (handle_one(philo))
		return (1);
	if (philo->eaten_meals == 0)
	{
		if (philo->id % 2 == 0)
			usleep(200);
		else if ((philo->data->philo_count % 2) != 0 && philo->id == 1)
			usleep(philo->time_to_eat * 1000);
	}
	sem_wait(philo->data->forks);
	print_status(philo, "has taken a fork");
	sem_wait(philo->data->forks);
	print_status(philo, "has taken a fork");
	return (0);
}

void	eat_and_sleep(t_philo *philo)
{
	sem_wait(philo->data->data_sem);
	philo->last_meal = get_time();
	print_status(philo, "is eating");
	sem_post(philo->data->data_sem);
	pass_time(philo, philo->time_to_eat * 50);
	sem_wait(philo->data->data_sem);
	philo->eaten_meals++;
	sem_post(philo->data->data_sem);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	if (end_simulation(philo) == 0 || end_simulation(philo) == 2)
	{
		print_status(philo, "is sleeping");
		pass_time(philo, philo->time_to_sleep * 50);
	}
}

int	handle_one(t_philo *philo)
{
	if (philo->data->philo_count == 1)
	{
		sem_wait(philo->data->data_sem);
		print_status(philo, "died");
		philo->data->life_state = DEAD;
		sem_post(philo->data->data_sem);
		return (1);
	}
	return (0);
}

void	think(t_philo *philo)
{
	print_status(philo, "is thinking");
	if (philo->data->philo_count % 2 == 0)
		usleep (philo->time_to_eat * 10);
	else
		usleep((philo->time_to_die - philo->time_to_eat \
				- philo->time_to_sleep) * 900);
}

/* void	pass_time(t_philo *philo, int i)
{
	if (i == 1)
	{
		if (philo->time_to_die < philo->time_to_eat)
			usleep(philo->time_to_die * 1000);
		else
			usleep(philo->time_to_eat * 1000);
	}
	if (i == 2)
	{
		if (philo->time_to_die < (philo->time_to_eat + philo->time_to_sleep))
			usleep((philo->time_to_die - philo->time_to_eat) * 1000);
		else
			usleep(philo->time_to_sleep * 1000);
	}
} */

void	pass_time(t_philo *philo, int time)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		usleep(time);
		if (end_simulation(philo) == 1)
			break ;
		i++;
	}
}
