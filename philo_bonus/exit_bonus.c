/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:26:25 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/14 11:23:18 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

//static void	kill_all(t_data *data);

void	ft_exit(t_data *data, char *msg, int status)
{
	if (data)
	{
		if (data->philos)
		{
			free(data->philos);
			data->philos = NULL;
		}
		sem_close(data->forks);
		sem_close(data->stop);
		sem_close(data->data_sem);
		sem_close(data->print_sem);
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
