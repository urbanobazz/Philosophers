/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:26:25 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/13 19:24:07 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

//static void	kill_all(t_data *data);

void	ft_exit(t_data *data, char *msg, int status)
{
	if (data)
	{
		//kill_all(data);
		if (data->philos)
		{
			free(data->philos);
			data->philos = NULL;
		}
		sem_close(data->forks);
		sem_close(data->data_sem);
		sem_close(data->print_sem);
		/* if (sem_unlink("stop_sem") == 0)
			printf("fdgjad"); */
		sem_unlink("stop_sem");
		sem_unlink("forks");
		sem_unlink("data_sem");
		sem_unlink("print_sem");
		free(data);
		data = NULL;
	}
	if (msg)
		printf("%s", msg);
	exit(status);
}

/* static void	kill_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
		kill(data->philos[i++].pid, SIGKILL);
} */
