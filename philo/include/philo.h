/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:03:34 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/10 17:07:29 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# ifndef LOCALE
#  define LOCALE 0
# endif

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
typedef struct timeval		t_timestamp;

typedef enum e_state
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DYING,
}	t_state;

typedef struct s_mutexval
{
	pthread_mutex_t	mutex;
	int				val;
}					t_mutexval;

typedef struct s_philo
{
	pthread_t	thread;
	t_mutexval	*l_fork;
	t_mutexval	*r_fork;
	t_mutexval	meals;
	t_state		state;
	t_timestamp	last_meal_ts;
	t_timestamp	state_since;
	t_mutexval	is_alive;
	char		*name;
	char		*roman;
}				t_philo;

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
	t_mutexval		*forks;
	t_routine_args	*args;
	t_timestamp		simulation_time;
	t_mutexval		a_philo_is_dead;
	t_mutexval		write;
}					t_philo_vars;

t_philo			*create_table(t_philo_vars *pvars, int argc, char **argv);
void			start_simulation(t_philo_vars *pvars);
void			*routine(t_routine_args *args);
void			display_state(t_routine_args *args);
long long		get_tv_diff(t_timestamp tv1, t_timestamp tv2);
void			clear_table(t_philo_vars *pvars);

void			philo_dies(t_routine_args *args);
void			philo_eats(t_routine_args *args);
void			philo_sleeps(t_routine_args *args);
void			philo_thinks(t_routine_args *args);

char			*int_to_roman(size_t nb);
void			print_fr(t_routine_args *args);
void			print_en(t_routine_args *args);
unsigned int	ft_atoui(const char *nptr, int *exit_code);
void			get_random_name(t_philo_vars *pvars, t_philo *ref);

#endif