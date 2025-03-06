/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:03:34 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/06 16:17:20 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"
# define GRAY "\x1b[37m"
# define RESET "\x1b[0m"
# define FORK_COLOR YELLOW
# define EATING_COLOR MAGENTA
# define SLEEPING_COLOR BLUE
# define THINKING_COLOR CYAN
# define DEAD_COLOR RED

typedef unsigned char		t_bool;
typedef unsigned int		t_id;
typedef unsigned long long	t_meals;
typedef struct timeval		t_timestamp;

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
}	t_state;

typedef enum e_move_ref
{
	TAKING_FORK,
	START_EATING,
	START_SLEEPING,
	START_THINKING,
	DYING,
}	t_move_ref;

typedef struct s_pfork
{
	pthread_mutex_t	mutex;
	t_bool			is_being_used;
}	t_pfork;

typedef struct s_philo
{
	pthread_t	thread;
	t_pfork		*l_fork;
	t_pfork		*r_fork;
	t_meals		meals;
	t_state		state;
	t_timestamp	last_meal_ts;
	t_timestamp	state_since;
}					t_philo;

typedef struct s_routine_args
{
	struct s_philo_vars	*pvars;
	t_philo				*philo;
	t_id				id;
	t_timestamp			ts;
}						t_routine_args;

typedef struct s_philo_vars
{
	int				exit_status;
	unsigned int	nb_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	nb_meals;
	t_bool			infinite_meals;
	t_philo			*philos;
	t_pfork			*forks;
	t_routine_args	*args;
	t_timestamp		sim_ts;
	t_bool			a_philo_is_dead;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	write;
}		t_philo_vars;

t_philo		*create_table(t_philo_vars *pvars);
t_philo		*create_threads(t_philo_vars *pvars);
void		*ret_malloc_error(t_philo_vars *pvars);
long long	get_tv_diff(t_timestamp tv1, t_timestamp tv2);
void		display_state(t_routine_args *args, t_move_ref move_ref);
void		philo_thinks(t_routine_args *args, t_philo *philo);
void		philo_eats(t_routine_args *args, t_philo *philo);
void		philo_sleeps(t_routine_args *args, t_philo *philo);
void		philo_dies(t_routine_args *args);
t_bool		comrade_is_dead(t_routine_args *args);
void		clear_the_table(t_philo_vars *pvars);

#endif