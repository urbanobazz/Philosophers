/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:28:02 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/11 15:05:49 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_one(t_philo *philo);

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (philo->eaten_meals == 0)
			usleep(200);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		if (handle_one(philo))
			return (1);
		if (philo->eaten_meals == 0
			&& (philo->data->philo_count % 2) != 0 && philo->id == 1)
			usleep(philo->time_to_eat * 1000);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	return (0);
}

void	eat_and_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_mutex);
	philo->last_meal = get_time();
	print_status(philo, "is eating");
	pthread_mutex_unlock(&philo->data->data_mutex);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->data->data_mutex);
	philo->eaten_meals++;
	pthread_mutex_unlock(&philo->data->data_mutex);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	print_status(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

int	handle_one(t_philo *philo)
{
	if (philo->data->philo_count == 1)
	{
		pthread_mutex_lock(&philo->data->data_mutex);
		print_status(philo, "died");
		philo->data->life_state = DEAD;
		pthread_mutex_unlock(&philo->data->data_mutex);
		return (1);
	}
	return (0);
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_mutex);
	print_status(philo, "is thinking");
	pthread_mutex_unlock(&philo->data->data_mutex);
	if (philo->data->philo_count % 2 == 0)
		usleep (philo->time_to_eat * 10);
	else
		usleep((philo->time_to_die - philo->time_to_eat \
				- philo->time_to_sleep) * 900);
}
