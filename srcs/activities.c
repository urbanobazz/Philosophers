/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:28:02 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/06 18:58:04 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_one(t_philo *philo);

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		usleep(200);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		if (philo->eaten_meals == 0 && (philo->data->philo_count % 2) != 0 && philo->id == 1)
			usleep(philo->time_to_eat * 1000);
		pthread_mutex_lock(philo->left_fork);
	}
	print_status(philo, "has taken a fork");
	if (handle_one(philo))
		return ;
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

int	is_alive(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->data->data_mutex);
	i = philo->data->life_state;
	pthread_mutex_unlock(&philo->data->data_mutex);
	if (i == ALIVE)
		return (1);
	else
		return (0);
}

int	handle_one(t_philo *philo)
{
	if (philo->data->philo_count == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
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
	print_status(philo, "is thinking");
	usleep(philo->time_to_eat * 10);
}
