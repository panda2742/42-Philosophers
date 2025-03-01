/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:03:34 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/01 22:30:19 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pfork
{
	struct s_philo	*left_philo;
	struct s_philo	*right_philo;
	pthread_mutex_t	mutex;
	struct s_philo	*user;
}	t_pfork;

typedef struct s_philo
{
	unsigned int	id;
	pthread_t		thread;
	struct s_philo	*left;
	struct s_philo	*right;
	t_pfork			*left_fork;
	t_pfork			*right_fork;
}					t_philo;

typedef struct s_philo_vars
{
	unsigned int	nb_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	nb_meals;
	unsigned char	infinite_meals;
	int				exit_status;
	t_philo			*philos;
}		t_philo_vars;

# define RED "\x1b[31m"
# define RESET "\x1b[0m"

void			*routine(t_philo_vars *pvars);
unsigned int	ft_atoui(const char *nptr, int *exit_code);
t_philo			*create_philo(t_philo_vars *pvars, unsigned int id, t_philo *left, t_philo *right);
t_pfork			*create_fork(t_philo_vars *pvars, t_philo *left_philo, t_philo *right_philo);
t_philo			**create_table(t_philo_vars *pvars);

#endif