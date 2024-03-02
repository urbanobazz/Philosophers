/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:57:39 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/02 14:29:07 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int arg)
{
	return (arg >= '0' && arg <= '9');
}

long	ft_atol(const char *str)
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

long	get_time(void)
{
	struct timeval tv;
	long long seconds;
	long long microseconds;
	long long milliseconds;

	gettimeofday(&tv, NULL);

	seconds = tv.tv_sec;
	microseconds = tv.tv_usec;
	milliseconds = seconds * 1000 + microseconds / 1000;
	return (milliseconds);
}
void	pass_time(long long time, t_philo *philo)
{
	long long start;

	start = get_time();
	while (get_time() - start < time && philo->data->life_state == ALIVE)
		usleep(100);
}
