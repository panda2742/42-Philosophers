/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:04:23 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/11 09:36:21 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_table(t_philo_vars *pvars)
{
	unsigned int	i;

	i = -1;
	while (++i < pvars->nb_philo)
	{
		pthread_mutex_destroy(&pvars->forks[i].mutex);
		if (pvars->philos[i].roman)
			free(pvars->philos[i].roman);
	}
	free(pvars->philos);
	free(pvars->forks);
	free(pvars->args);
}
