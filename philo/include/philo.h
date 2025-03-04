/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:03:34 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/04 13:55:32 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char t_bool;

typedef struct s_pfork
{
	pthread_mutex_t	mutex;
	t_bool			is_being_used;
}	t_pfork;

typedef struct s_philo
{
	pthread_t		thread;
	t_pfork			*l_fork;
	t_pfork			*r_fork;
}					t_philo;

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
}		t_philo_vars;

typedef struct s_routine_args
{
	t_philo_vars	*pvars;
	t_philo			*philo;
}					t_routine_args;

# define RED "\x1b[31m"
# define RESET "\x1b[0m"

void			*routine(t_philo_vars *pvars);
t_philo			*create_table(t_philo_vars *pvars);

#endif