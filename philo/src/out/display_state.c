/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:33:36 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/11 10:27:31 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*_get_color(t_routine_args *args);

void	display_state(t_routine_args *args)
{
	const ssize_t	ms = get_tv_diff(args->ts, args->pvars->simulation_time);

	pthread_mutex_lock(&args->pvars->write.mutex);
	printf("%s%zd ", _get_color(args), ms);
	if (LOCALE == 0)
		print_en(args);
	else if (LOCALE == 1)
		print_fr(args);
	printf("\n" RESET);
	pthread_mutex_unlock(&args->pvars->write.mutex);
}

static char	*_get_color(t_routine_args *args)
{
	if (args->philo->state == TAKING_FORK)
		return (FORK_COLOR);
	if (args->philo->state == EATING)
		return (EATING_COLOR);
	if (args->philo->state == SLEEPING)
		return (SLEEPING_COLOR);
	if (args->philo->state == THINKING)
		return (SLEEPING_COLOR);
	if (args->philo->state == DYING)
		return (DEAD_COLOR);
	return ("");
}
