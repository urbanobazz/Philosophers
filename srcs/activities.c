/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:28:02 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/02 12:54:12 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	life_state(t_philo *philo)
{
	long long	time;

	time = get_time();
	if (time - philo->last_meal > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->data_mutex);
		printf("%lld %ld died\n", time - philo->data->starting_time, philo->id);
		philo->data->life_state = DEAD;
		pthread_mutex_unlock(&philo->data->data_mutex);
		return (DEAD);
	}
	return (ALIVE);
}
int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	if (life_state(philo) == ALIVE)
		printf("%lld %ld has taken a fork\n", get_time() - philo->data->starting_time, philo->id);
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
			pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
			pthread_mutex_unlock(philo->left_fork);
	}
	if (life_state(philo) == ALIVE)
	{
		printf("%lld %ld has taken a fork\n", get_time() - philo->data->starting_time, philo->id);
		return (ALIVE);
	}
	return (DEAD);
}
int	eating(t_philo *philo)
{
	if (life_state(philo) == ALIVE)
	{
		printf("%lld %ld is eating\n", get_time() - philo->data->starting_time, philo->id);
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
	if (life_state(philo) == ALIVE)
	{
		printf("%lld %ld is sleeping\n", get_time() - philo->data->starting_time, philo->id);
		pass_time(philo->data->time_to_sleep, philo);
		return (ALIVE);
	}
	return (DEAD);
}

int	thinking(t_philo *philo)
{
	if (life_state(philo) == ALIVE)
	{
		printf("%lld %ld is thinking\n", get_time() - philo->data->starting_time, philo->id);
		return (ALIVE);
	}
	return (DEAD);
}
