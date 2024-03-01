/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:25:05 by ubazzane          #+#    #+#             */
/*   Updated: 2024/02/29 20:45:13 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	long			id;
	long			last_meal;
	long			eaten_meals;
	pthread_t		thread_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}				t_philo;

typedef struct s_data
{
	long			philo_count;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long			meals_count;
	long			starting_time;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}				t_data;

// Utils
int			ft_isdigit(int arg);
long long	ft_atoi(const char *str);

// Exit
void	exit_error(t_data *data, char *msg);

// input_check
void	validate_input(int argc, char **argv);


#endif
