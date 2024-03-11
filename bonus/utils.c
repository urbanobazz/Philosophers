/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:57:39 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/11 15:31:35 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_isdigit(int arg)
{
	return (arg >= '0' && arg <= '9');
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res > INT_MAX / 10 || res * 10 > INT_MAX - (*str - '0'))
			return (-1);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

long	get_time(void)
{
	struct timeval	tv;
	long long		seconds;
	long long		microseconds;
	long long		milliseconds;

	gettimeofday(&tv, NULL);
	seconds = tv.tv_sec;
	microseconds = tv.tv_usec;
	milliseconds = seconds * 1000 + microseconds / 1000;
	return (milliseconds);
}

void	print_status(t_philo *philo, char *status)
{
	sem_wait(&philo->data->print_sem);
	if (philo->data->life_state == ALIVE)
		printf("%ld %d %s\n", get_time() - philo->data->starting_time, \
				philo->id, status);
	sem_post(&philo->data->print_sem);
}
