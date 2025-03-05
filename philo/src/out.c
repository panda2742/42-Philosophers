/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:05:02 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/05 12:51:45 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*_get_color(t_state state);

void	display_state(t_routine_args *args, unsigned long long ts, t_state state)
{
	if (state == SPWANING)
		printf("%s%llu %d is born%s\n", _get_color(state), ts, args->id, RESET);
	if (state == FORK_TAKEN)
		printf("%s%llu %d has taken a fork%s\n", _get_color(state), ts, args->id, RESET);
	if (state == EATING)
		printf("%s%llu %d is eating%s\n", _get_color(state), ts, args->id, RESET);
	if (state == SLEEPING)
		printf("%s%llu %d is sleeping%s\n", _get_color(state), ts, args->id, RESET);
	if (state == THINKING)
		printf("%s%llu %d is thinking%s\n", _get_color(state), ts, args->id, RESET);
	if (state == DEAD)
		printf("%s%llu %d died%s\n", _get_color(state), ts, args->id, RESET);
}

static char	*_get_color(t_state state)
{
	if (state == SPWANING)
		return (SPAWNING_COLOR);
	if (state == FORK_TAKEN)
		return (FORK_TAKEN_COLOR);
	if (state == EATING)
		return (EATING_COLOR);
	if (state == SLEEPING)
		return (SLEEPING_COLOR);
	if (state == THINKING)
		return (THINKING_COLOR);
	if (state == DEAD)
		return (DEAD_COLOR);
	return "";
}
