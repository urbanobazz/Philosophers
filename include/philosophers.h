/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:25:05 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/02 14:41:10 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

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
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	long			philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_count;
	long			starting_time;
	int				turns;
	int				life_state;
	pthread_mutex_t	*forks;
	pthread_mutex_t	data_mutex;
	pthread_mutex_t	print_mutex;
	t_philo			*philos;
}				t_data;

// Data init
t_data		*data_init(int argc, char **argv);

// Philo init
void		init_philosophers(t_data *data);

// Monitor
void		monitor_philosophers(t_data *data);

// Utils
int			ft_isdigit(int arg);
long		ft_atol(const char *str);
long		get_time(void);
void		pass_time(long long time, t_philo *philo);
void		print_status(t_philo *philo, char *status);

// Exit
void	ft_exit(t_data *data, char *msg, int status);

// Activities
int		take_forks(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);

#endif
