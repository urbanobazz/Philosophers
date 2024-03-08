/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:26:25 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/08 17:26:36 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	free_forks(t_data *data);

void	ft_exit(t_data *data, char *msg, int status)
{
	if (data)
	{
		if (data->forks)
			free_forks(data);
		if (data->philos)
			free(data->philos);
		pthread_mutex_destroy(&data->data_mutex);
		pthread_mutex_destroy(&data->print_mutex);
		free(data);
	}
	if (msg)
		printf("%s", msg);
	exit(status);
}

static void	free_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}
