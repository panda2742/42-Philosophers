/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thinks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:59:08 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/11 09:29:36 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	_forks_are_free(t_routine_args *args);

void	philo_thinks(t_routine_args *args)
{
	pthread_mutex_lock(&args->philo->l_fork->mutex);
	if (args->pvars->nb_philo > 1)
		pthread_mutex_lock(&args->philo->r_fork->mutex);
	if (_forks_are_free(args))
	{
		args->philo->state = TAKING_FORK;
		args->philo->state_since = args->ts;
		display_state(args);
		args->philo->l_fork->val = 1;
		pthread_mutex_unlock(&args->philo->l_fork->mutex);
		args->philo->state_since = args->ts;
		display_state(args);
		args->philo->r_fork->val = 1;
		pthread_mutex_unlock(&args->philo->r_fork->mutex);
		args->philo->state = EATING;
		args->philo->state_since = args->ts;
		display_state(args);
	}
	else
	{
		pthread_mutex_unlock(&args->philo->l_fork->mutex);
		pthread_mutex_unlock(&args->philo->r_fork->mutex);
	}
}

static t_bool	_forks_are_free(t_routine_args *args)
{
	return (args->philo->l_fork->val == 0
		&& args->philo->r_fork->val == 0
		&& args->philo->l_fork != args->philo->r_fork);
}
