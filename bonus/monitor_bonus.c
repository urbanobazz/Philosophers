/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:42:39 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/13 18:33:02 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

/* static int	check_life_state(t_philo *philo);
static int	check_meals_eaten(t_philo *philo);

void	*monitor_philosophers(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(500);
		if (check_life_state(philo) == DEAD)
			break ;
		if (check_meals_eaten(philo))
			break ;
	}
	return (0);
}

static int	check_life_state(t_philo *philo)
{
	long	time;

	time = get_time();
	sem_wait(philo->data_sem);
	if (time - philo->last_meal > philo->time_to_die)
	{
		print_status(philo, "died");
		philo->life_state = DEAD;
		sem_post(philo->data_sem);
		return (DEAD);
	}
	sem_post(philo->data_sem);
	return (ALIVE);
}

static int	check_meals_eaten(t_philo *philo)
{
	sem_wait(philo->data_sem);
	if (philo->eaten_meals == philo->data->meals_count)
	{
		sem_post(philo->data_sem);
		return (1);
	}
	sem_post(philo->data_sem);
	return (0);
}
 */
