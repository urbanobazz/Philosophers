/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:20:01 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/01 23:07:04 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_error(t_data *data, char *msg)
{
	if (data)
	{
		if (data->forks)
			free_forks(data);
		if (data->philos)
			free_philos(data->philos);
	}
		free(data->philos);
	if (msg)
		printf("%s", msg);
	exit(EXIT_FAILURE);
}

void	free_forks(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}

