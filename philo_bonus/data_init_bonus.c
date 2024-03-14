/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:16:46 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/14 10:07:34 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	philos_init(t_data *data);

t_data	*data_init(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_exit(NULL, "Malloc error\n", 1);
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_count = ft_atoi(argv[5]);
	else
		data->meals_count = -1;
	data->starting_time = 0;
	data->life_state = ALIVE;
	sem_unlink("stop_sem");
	sem_unlink("forks");
	sem_unlink("data_sem");
	sem_unlink("print_sem");
	data->stop = sem_open("stop_sem", O_CREAT, 0644, 1);
	data->forks = sem_open("forks", O_CREAT, 0644, data->philo_count);
	data->data_sem = sem_open("data_sem", O_CREAT, 0644, 1);
	data->print_sem = sem_open("print_sem", O_CREAT, 0644, 1);
	philos_init(data);
	return (data);
}

static void	philos_init(t_data *data)
{
	int	i;

	i = 0;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		ft_exit(data, "Malloc error(2)\n", 1);
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->time_to_die;
		data->philos[i].time_to_eat = data->time_to_eat;
		data->philos[i].time_to_sleep = data->time_to_sleep;
		data->philos[i].last_meal = 0;
		data->philos[i].eaten_meals = 0;
		data->philos[i].pid = -1;
		data->philos[i].data = data;
		data->philos[i].life_state = ALIVE;
		i++;
	}
}
