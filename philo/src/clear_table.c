/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:13:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/06 16:18:20 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_clear_philos(t_philo_vars *pvars);
void	_clear_forks(t_philo_vars *pvars);

void	clear_the_table(t_philo_vars *pvars)
{

	if (pvars->philos)
		_clear_philos(pvars);
	if (pvars->forks)
		_clear_forks(pvars);
	if (pvars->args)
		free(pvars->args);
	pthread_mutex_destroy(&pvars->dead_mutex);
	pthread_mutex_destroy(&pvars->write);
}

void	_clear_philos(t_philo_vars *pvars)
{
	unsigned int	i;

	i = -1;
	while (++i < pvars->nb_philo)
		pthread_detach(pvars->philos[i].thread);
	free(pvars->philos);
}

void	_clear_forks(t_philo_vars *pvars)
{
	unsigned int	i;

	i = -1;
	while (++i < pvars->nb_philo)
		pthread_mutex_destroy(&pvars->forks[i].mutex);
	free(pvars->forks);
}
