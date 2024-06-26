/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:23:12 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/14 11:45:48 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	validate_input(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_data		*data;

	validate_input(argc, argv);
	data = data_init(argc, argv);
	create_philos(data);
	wait_for_philos(data);
	ft_exit(data, NULL, 0);
	return (0);
}

static void	validate_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 5 || argc == 6)
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				if (!ft_isdigit(argv[i][j]))
					ft_exit(NULL, "Invalid input: arguments \
									must be composed of numbers\n", 1);
				j++;
			}
			if (ft_atoi(argv[i]) == -1)
				ft_exit(NULL, "Invalid argument", 1);
			if (i == 1 && ft_atoi(argv[i]) > 200)
				ft_exit(NULL, "ERROR: Philosophers limit exceeded", 1);
			i++;
		}
	}
	else
		ft_exit(NULL, "Invalid argument amount\n", 1);
}

static int	check_exit(t_data *data, int code)
{
	int	i;

	i = 0;
	if (code == DEAD)
	{
		while (i < data->philo_count)
		{
			kill(data->philos[i].pid, SIGTERM);
			i++;
		}
		sem_post(data->print_sem);
		return (DEAD);
	}
	return (ALIVE);
}

void	wait_for_philos(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->philo_count)
	{
		waitpid(-1, &status, 0);
		check_exit(data, WEXITSTATUS(status));
		i++;
	}
}
