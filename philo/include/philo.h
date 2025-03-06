/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:03:34 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/05 21:35:22 by ehosta           ###   ########.fr       */
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

# define SPAWNING_COLOR GREEN
# define FORK_TAKEN_COLOR YELLOW
# define EATING_COLOR MAGENTA
# define SLEEPING_COLOR BLUE
# define THINKING_COLOR CYAN
# define DEAD_COLOR RED

typedef enum e_state
{
	SPAWNING,
	FORK_TAKEN,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_state;

typedef unsigned char t_bool;
typedef long long t_timestamp;

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
}					t_philo;

typedef struct s_routine_args
{
	struct s_philo_vars	*pvars;
	t_philo				*philo;
	unsigned int		id;
	t_timestamp			ts;
}						t_routine_args;

typedef struct s_philo_vars
{
	unsigned int	nb_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	nb_meals;
	t_bool			infinite_meals;
	int				exit_status;
	t_philo			*philos;
	t_pfork			*forks;
	t_routine_args	*args;
}		t_philo_vars;

t_philo		*create_table(t_philo_vars *pvars);
t_philo		*create_threads(t_philo_vars *pvars);
void		*ret_malloc_error(t_philo_vars *pvars);
void		display_state(t_routine_args *args, unsigned long long ts, t_state state);
long long	date_now(void);
void		lock_forks(t_pfork *l_fork, t_pfork *r_fork);
void		unlock_forks(t_pfork *l_fork, t_pfork *r_fork);

#endif