/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:01:30 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/10 16:36:07 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dies(t_routine_args *args)
{
	pthread_mutex_lock(&args->pvars->a_philo_is_dead.mutex);
	pthread_mutex_lock(&args->philo->is_alive.mutex);
	args->philo->state = DYING;
	args->philo->state_since = args->ts;
	display_state(args);
	args->pvars->a_philo_is_dead.val = 1;
	args->philo->is_alive.val = 0;
	pthread_mutex_unlock(&args->pvars->a_philo_is_dead.mutex);
	pthread_mutex_unlock(&args->philo->is_alive.mutex);
}
