/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:25:05 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/01 23:07:34 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define DEAD 1
# define ALIVE 0

typedef struct s_philo
{
	long			id;
	long			last_meal;
	long			eaten_meals;
	pthread_t		thread_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			*data;
}				t_philo;

typedef struct s_data
{
	long			philo_count;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long			meals_count;
	long			starting_time;
	int				turns;
	int				life_state;
	pthread_mutex_t	*forks;
	pthread_mutex_t	data_mutex;
	t_philo			*philos;
}				t_data;

// Utils
int			ft_isdigit(int arg);
long long	ft_atoi(const char *str);
long long	get_time(void);
void		pass_time(long long time, t_philo *philo);

// Exit
void	exit_error(t_data *data, char *msg);

// Activities
int		life_state(t_philo *philo);
int		take_forks(t_philo *philo);
int		eat(t_philo *philo);
int		sleep(t_philo *philo);
int		think(t_philo *philo);

#endif
