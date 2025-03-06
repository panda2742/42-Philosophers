/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:40:07 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/05 21:41:19 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*_routine(t_routine_args *args);

t_philo	*create_table(t_philo_vars *pvars)
{
	unsigned int	i;
	unsigned int	j;

	pvars->philos = malloc(sizeof(t_philo) * pvars->nb_philo);
	if (pvars->philos == NULL)
		return (ret_malloc_error(pvars));
	pvars->forks = malloc(sizeof(t_pfork) * pvars->nb_philo);
	if (pvars->forks == NULL)
		return (ret_malloc_error(pvars));
	pvars->args = malloc(sizeof(t_routine_args) * pvars->nb_philo);
	if (pvars->forks == NULL)
		return (ret_malloc_error(pvars));
	i = -1;
	while (++i < pvars->nb_philo)
	{
		j = i + 1;
		if (j >= pvars->nb_philo)
			j = 0;
		pvars->philos[i].r_fork = &pvars->forks[i];
		pvars->philos[j].l_fork = &pvars->forks[i];
		pvars->forks[i].is_being_used = 0;
		pvars->args[i].id = i;
	}
	return (&pvars->philos[0]);
}

t_philo	*create_threads(t_philo_vars *pvars)
{
	unsigned int	i;

	i = -1;
	while (++i < pvars->nb_philo)
	{
		pthread_mutex_init(&pvars->forks[i].mutex, NULL);
		pvars->args[i].philo = &pvars->philos[i];
		pvars->args[i].pvars = pvars;
		pthread_create(
			&pvars->philos[i].thread, NULL,
			(void *(*)(void *))_routine, (void *)&pvars->args[i]);
	}
	i = -1;
	while (++i < pvars->nb_philo)
		pthread_join(pvars->philos[i].thread, NULL);
	return (NULL);
}

static void	*_routine(t_routine_args *args)
{
	t_bool		is_alive;
	t_pfork		*l_fork;
	t_pfork		*r_fork;
	t_bool		is_eating;

	l_fork = args->philo->l_fork;
	r_fork = args->philo->r_fork;
	is_alive = 1;
	display_state(args, 0, SPAWNING);
	while (is_alive)
	{
		args->ts = date_now();
		usleep(500);
	}
	display_state(args, args->ts / 1000, DEAD);
	return (NULL);
}

t_timestamp	date_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000) + tv.tv_usec;
}
