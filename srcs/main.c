/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:48:15 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/04 20:19:34 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	validate_input(int argc, char **argv);

int main(int argc, char **argv)
{
	t_data		*data;

	validate_input(argc, argv);
	data = data_init(argc, argv);
	init_philosophers(data);
	monitor_philosophers(data);
	join_threads(data);
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
					ft_exit(NULL, "Invalid input: arguments must be composed of numbers\n", 1);
				j++;
			}
			if (ft_atoi(argv[i]) == -1)
				ft_exit(NULL, "Invalid argument", 1);
			i++;
		}
	}
	else
		ft_exit(NULL, "Invalid argument amount\n", 1);
}
