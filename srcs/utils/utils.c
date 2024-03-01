/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:57:39 by ubazzane          #+#    #+#             */
/*   Updated: 2024/02/29 19:02:42 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int arg)
{
	return (arg >= '0' && arg <= '9');
}

long long	ft_atoi(const char *str)
{
	long long	res;
	long long	sign;
	int	sign_count;

	res = 0;
	sign = 1;
	sign_count = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		sign_count++;
	}
	if (sign_count > 1)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}
