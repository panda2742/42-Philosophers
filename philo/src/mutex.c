/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:27:52 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/05 19:30:48 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_pfork *l_fork, t_pfork *r_fork)
{
	pthread_mutex_lock(&l_fork->mutex);
	pthread_mutex_lock(&r_fork->mutex);
}

void	unlock_forks(t_pfork *l_fork, t_pfork *r_fork)
{
	pthread_mutex_unlock(&l_fork->mutex);
	pthread_mutex_unlock(&r_fork->mutex);
}
