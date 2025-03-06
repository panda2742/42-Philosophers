/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:05:02 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/06 15:24:42 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_state(t_routine_args *args, t_move_ref move_ref)
{
	const ssize_t	ms = get_tv_diff(args->ts, args->pvars->sim_ts);

	pthread_mutex_lock(&args->pvars->write);
	if (move_ref == TAKING_FORK)
		printf(FORK_COLOR "%zd %d has taken a fork\n" RESET, ms, args->id);
	if (move_ref == START_EATING)
		printf(EATING_COLOR "%zd %d is eating\n" RESET, ms, args->id);
	if (move_ref == START_SLEEPING)
		printf(SLEEPING_COLOR "%zd %d is sleeping\n" RESET, ms, args->id);
	if (move_ref == START_THINKING)
		printf(THINKING_COLOR "%zd %d is thinking\n" RESET, ms, args->id);
	if (move_ref == DYING)
		printf(DEAD_COLOR "%zd %d died\n" RESET, ms, args->id);
	pthread_mutex_unlock(&args->pvars->write);
}
