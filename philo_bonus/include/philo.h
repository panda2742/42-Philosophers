/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:09:15 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/11 11:16:05 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

typedef enum e_state
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DYING,
}	t_state;

typedef struct s_philo_vars
{
	int				exit_status;
	unsigned int	nb_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	nb_meals;
	t_bool			infinite_meals;
}					t_philo_vars;

void			parsing(t_philo_vars *pvars, int argc, char **argv);
unsigned int	ft_atoui(const char *nptr, int *exit_code);

#endif