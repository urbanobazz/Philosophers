/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:24:08 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/11 17:49:56 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <limits.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>


# define DEAD 1
# define ALIVE 0

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				eaten_meals;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				life_state;
	int				pid;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_count;
	long			starting_time;
	int				stop;
	int				life_state;
	sem_t			*forks; // change to sem_t
	sem_t			*data_sem;
	sem_t			*print_sem;
	t_philo			*philos;
}				t_data;

// data_init
t_data	*data_init(int argc, char **argv);

// exit
void	ft_exit(t_data *data, char *msg, int status);

// Utils
int			ft_isdigit(int arg);
int			ft_atoi(const char *str);
long		get_time(void);
void		print_status(t_philo *philo, char *status);

// Activities
int		take_forks(t_philo *philo);
void	eat_and_sleep(t_philo *philo);
int		handle_one(t_philo *philo);
void	think(t_philo *philo);

// Routine
void	routine(t_philo *philo);
void	create_philos(t_data *data);
void	set_counter(t_data *data);

// Monitor
void	*monitor_philosophers(void *arg);

//routine
void	routine(t_philo *philo);
void	create_philos(t_data *data);
void	set_counter(t_data *data);

#endif
