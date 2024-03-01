/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:48:15 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/01 20:02:46 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	validate_input(int argc, char **argv);

int main(int argc, char **argv)
{
	t_data		*data;

	validate_input(argc, argv);
	data_init(data, argc, argv);

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
					exit_error(NULL, "Invalid input: arguments must be composed of numbers\n");
				j++;
			}
			if (ft_atoi(argv[i]) <= 0)
				exit_error(NULL, "Invalid argument");
			i++;
		}
	}
	else
		exit_error(NULL, "Invalid argument amount\n");
}
void	check_arg(char *argv, int i)
{
	if (ft_atoi(argv) == 0)
		exit_error(NULL, "Invalid argument");
}
