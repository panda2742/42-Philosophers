/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:49:31 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/10 20:14:59 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	_comrade_is_dead(t_routine_args *args);
static t_bool	_everyone_ate(t_routine_args *args);

void	*routine(t_routine_args *args)
{
	t_philo			*philo;

	philo = args->philo;
	philo->state = THINKING;
	gettimeofday(&philo->state_since, NULL);
	display_state(args);
	while (!_everyone_ate(args))
	{
		gettimeofday(&args->ts, NULL);
		if (_comrade_is_dead(args))
			break ;
		if (get_tv_diff(args->ts, philo->last_meal_ts) >= args->pvars->t_die)
			philo_dies(args);
		else if (philo->state == THINKING)
			philo_thinks(args);
		else if (philo->state == EATING)
			philo_eats(args);
		else if (philo->state == SLEEPING)
			philo_sleeps(args);
		usleep(500);
	}
	pthread_detach(philo->thread);
	return (NULL);
}

static t_bool	_everyone_ate(t_routine_args *args)
{
	unsigned int	i;

	if (args->pvars->infinite_meals)
		return (0);
	i = -1;
	while (++i < args->pvars->nb_philo)
	{	
		pthread_mutex_lock(&args->pvars->philos[i].meals.mutex);
		if ((unsigned int)args->pvars->philos[i].meals.val
			< args->pvars->nb_meals)
		{
			pthread_mutex_unlock(&args->pvars->philos[i].meals.mutex);
			return (0);
		}
		pthread_mutex_unlock(&args->pvars->philos[i].meals.mutex);
	}
	return (1);
}

static t_bool	_comrade_is_dead(t_routine_args *args)
{
	unsigned int	i;

	i = -1;
	while (++i < args->pvars->nb_philo)
	{
		pthread_mutex_lock(&args->pvars->philos[i].is_alive.mutex);
		if (args->pvars->philos[i].is_alive.val == 0)
		{
			pthread_mutex_unlock(&args->pvars->philos[i].is_alive.mutex);
			return (1);
		}
		pthread_mutex_unlock(&args->pvars->philos[i].is_alive.mutex);
	}
	return (0);
}
