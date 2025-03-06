/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:40:07 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/06 16:21:58 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		*_routine(t_routine_args *args);
static t_bool	_everyone_ate(t_routine_args *args);

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
	clear_the_table(pvars);
	return (NULL);
}

static void	*_routine(t_routine_args *args)
{
	t_philo	*philo;

	philo = args->philo;
	gettimeofday(&args->ts, NULL);
	gettimeofday(&philo->last_meal_ts, NULL);
	philo->state = THINKING;
	display_state(args, START_THINKING);
	while (!_everyone_ate(args))
	{
		gettimeofday(&args->ts, NULL);
		if (comrade_is_dead(args))
			break ;
		if (get_tv_diff(args->ts, philo->last_meal_ts) >= args->pvars->t_die)
			philo_dies(args);
		else if (philo->state == THINKING)
			philo_thinks(args, philo);
		else if (philo->state == EATING)
			philo_eats(args, philo);
		else if (philo->state == SLEEPING)
			philo_sleeps(args, philo);
		usleep(500);
	}
	return (NULL);
}

static t_bool	_everyone_ate(t_routine_args *args)
{
	unsigned int	i;

	if (args->pvars->infinite_meals)
		return (0);
	i = -1;
	while (++i < args->pvars->nb_philo)
	{
		if (args->pvars->philos[i].meals < args->pvars->nb_meals)
			return (0);
	}
	return (1);
}
