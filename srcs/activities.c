/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:28:02 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/05 18:27:12 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	if (philo->data->philo_count == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_lock(&philo->data->data_mutex);
		philo->data->life_state = DEAD;
		pthread_mutex_unlock(&philo->data->data_mutex);
		return ;
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
}
void	eating(t_philo *philo)
{
	if (is_alive(philo))
	{
		print_status(philo, "is eating");
		philo->last_meal = get_time();
		usleep(philo->data->time_to_eat * 1000);
		philo->eaten_meals++;
	}
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleep_and_think(t_philo *philo)
{
	if (is_alive(philo))
	{
		print_status(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
		print_status(philo, "is thinking");
	}
}

int	is_alive(t_philo *philo)
{

	if (philo->data->life_state == ALIVE)
		return (1);
	else
		return (0);
}
