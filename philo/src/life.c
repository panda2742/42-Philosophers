/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:53:00 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/06 16:02:12 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_thinks(t_routine_args *args, t_philo *philo)
{
	pthread_mutex_lock(&args->philo->l_fork->mutex);
	pthread_mutex_lock(&args->philo->r_fork->mutex);
	if (args->philo->l_fork->is_being_used == 0
		&& args->philo->r_fork->is_being_used == 0
		&& args->philo->l_fork != args->philo->r_fork)
	{
		display_state(args, TAKING_FORK);
		args->philo->l_fork->is_being_used = 1;
		pthread_mutex_unlock(&args->philo->l_fork->mutex);
		display_state(args, TAKING_FORK);
		args->philo->r_fork->is_being_used = 1;
		pthread_mutex_unlock(&args->philo->r_fork->mutex);
		display_state(args, START_EATING);
		philo->state = EATING;
		philo->state_since = args->ts;
	}
	else
	{
		pthread_mutex_unlock(&args->philo->l_fork->mutex);
		pthread_mutex_unlock(&args->philo->r_fork->mutex);
	}
}

void	philo_eats(t_routine_args *args, t_philo *philo)
{
	if (get_tv_diff(args->ts, philo->state_since) >= args->pvars->t_eat)
	{
		pthread_mutex_lock(&args->philo->l_fork->mutex);
		pthread_mutex_lock(&args->philo->r_fork->mutex);
		args->philo->l_fork->is_being_used = 0;
		args->philo->r_fork->is_being_used = 0;
		pthread_mutex_unlock(&args->philo->l_fork->mutex);
		pthread_mutex_unlock(&args->philo->r_fork->mutex);
		display_state(args, START_SLEEPING);
		philo->state = SLEEPING;
		philo->state_since = args->ts;
		philo->last_meal_ts = args->ts;
		philo->meals += 1;
	}
}

void	philo_sleeps(t_routine_args *args, t_philo *philo)
{
	if (get_tv_diff(args->ts, philo->state_since) >= args->pvars->t_sleep)
	{
		display_state(args, START_THINKING);
		philo->state = THINKING;
		philo->state_since = args->ts;
	}
}

void	philo_dies(t_routine_args *args)
{
	display_state(args, DYING);
	pthread_mutex_lock(&args->pvars->dead_mutex);
	args->pvars->a_philo_is_dead = 1;
	pthread_mutex_unlock(&args->pvars->dead_mutex);
}

t_bool	comrade_is_dead(t_routine_args *args)
{
	pthread_mutex_lock(&args->pvars->dead_mutex);
	if (args->pvars->a_philo_is_dead)
	{
		pthread_mutex_unlock(&args->pvars->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&args->pvars->dead_mutex);
	return (0);
}
