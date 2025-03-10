/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:49:41 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/10 17:11:20 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_en(t_routine_args *args)
{
	if (args->philo->state == TAKING_FORK)
		printf("%d has taken a fork", args->id);
	if (args->philo->state == EATING)
		printf("%d is eating", args->id);
	if (args->philo->state == SLEEPING)
		printf("%d is sleeping", args->id);
	if (args->philo->state == THINKING)
		printf("%d is thinking", args->id);
	if (args->philo->state == DYING)
		printf("%d died", args->id);
}
