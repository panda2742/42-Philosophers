/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:01:34 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/06 16:12:52 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ret_malloc_error(t_philo_vars *pvars)
{
	pvars->exit_status = EXIT_FAILURE;
	printf(RED "Error.\n  Memory allocation failed.\n" RESET);
	return (NULL);
}

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

long long	get_tv_diff(t_timestamp tv1, t_timestamp tv2)
{
	long long	secs;
	long long	usecs;
	long long	res;

	if (tv1.tv_sec == 0)
		gettimeofday(&tv1, NULL);
	if (tv2.tv_sec == 0)
		gettimeofday(&tv2, NULL);
	secs = tv1.tv_sec - tv2.tv_sec;
	usecs = tv1.tv_usec - tv2.tv_usec;
	res = secs * 1000 + usecs / 1000;
	return (res);
}
