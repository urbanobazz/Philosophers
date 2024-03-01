/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:28:02 by ubazzane          #+#    #+#             */
/*   Updated: 2024/02/29 19:28:28 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	validate_input(int argc, char **argv)
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
			i++;
		}
	}
	else
		exit_error(NULL, "Invalid argument amount\n");
}
