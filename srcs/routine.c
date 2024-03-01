/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:55:58 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/01 22:56:18 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->data->life_state == ALIVE)
	{
		if (is_dead(philo) == DEAD)
			return (0);
		if (take_forks(philo) == DEAD)
			return (0);
		if (eat(philo) == DEAD)
			return (0);
		if (sleep(philo) == DEAD)
			return (0);
		if (think(philo) == DEAD)
			return (0);
	}
	return (0);
}
