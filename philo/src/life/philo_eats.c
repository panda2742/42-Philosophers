/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:01:38 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/10 16:37:40 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eats(t_routine_args *args)
{
	if (get_tv_diff(args->ts, args->philo->state_since) >= args->pvars->t_eat)
	{
		pthread_mutex_lock(&args->philo->l_fork->mutex);
		pthread_mutex_lock(&args->philo->r_fork->mutex);
		args->philo->l_fork->val = 0;
		args->philo->r_fork->val = 0;
		pthread_mutex_unlock(&args->philo->l_fork->mutex);
		pthread_mutex_unlock(&args->philo->r_fork->mutex);
		args->philo->state = SLEEPING;
		args->philo->state_since = args->ts;
		args->philo->last_meal_ts = args->ts;
		display_state(args);
		pthread_mutex_lock(&args->philo->meals.mutex);
		args->philo->meals.val += 1;
		pthread_mutex_unlock(&args->philo->meals.mutex);
	}
}
