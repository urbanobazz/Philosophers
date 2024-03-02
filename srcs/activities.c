/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:28:02 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/02 16:56:13 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	if (philo->data->life_state == ALIVE)
		print_status(philo, "has taken a fork");
	if (philo->data->philo_count == 1)
		return (pthread_mutex_unlock(philo->left_fork), DEAD);
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
			return (pthread_mutex_unlock(philo->right_fork), DEAD);
		if (philo->data->life_state == ALIVE)
			print_status(philo, "has taken a fork");
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
			return (pthread_mutex_unlock(philo->left_fork), DEAD);
		if (philo->data->life_state == ALIVE)
			print_status(philo, "has taken a fork");
	}
	return (ALIVE);
}
int	eating(t_philo *philo)
{
	if (philo->data->life_state == ALIVE)
	{
		print_status(philo, "is eating");
		philo->last_meal = get_time();
		pass_time(philo->data->time_to_eat, philo);
		philo->eaten_meals++;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (ALIVE);
	}
	return (DEAD);
}

int	sleeping(t_philo *philo)
{
	if (philo->data->life_state == ALIVE)
	{
		print_status(philo, "is sleeping");
		pass_time(philo->data->time_to_sleep, philo);
		return (ALIVE);
	}
	return (DEAD);
}

int	thinking(t_philo *philo)
{
	if (philo->data->life_state == ALIVE)
	{
		print_status(philo, "is thinking");
		//usleep(10);
		return (ALIVE);
	}
	return (DEAD);
}
