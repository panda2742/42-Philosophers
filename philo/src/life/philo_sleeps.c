/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleeps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:01:46 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/10 17:24:04 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleeps(t_routine_args *args)
{
	if (get_tv_diff(args->ts, args->philo->state_since) >= args->pvars->t_sleep)
	{
		args->philo->state = THINKING;
		args->philo->state_since = args->ts;
		display_state(args);
		usleep(1000);
	}
}
