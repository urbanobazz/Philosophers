/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:20:01 by ubazzane          #+#    #+#             */
/*   Updated: 2024/02/29 19:23:15 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_error(t_data *data, char *msg)
{
	if (data)
		free(data->philos);
	if (msg)
		printf("%s", msg);
	exit(EXIT_FAILURE);
}
