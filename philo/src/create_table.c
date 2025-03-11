/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:28:08 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/11 10:36:01 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_exec_parsing(t_philo_vars *pvars, int argc, char **argv);
static void	_init_philo(t_philo_vars *pvars);
static void	_join_threads(t_philo_vars *pvars);

void	create_table(t_philo_vars *pvars, int argc, char **argv)
{
	_exec_parsing(pvars, argc, argv);
	if (pvars->exit_status == EXIT_FAILURE)
		return ;
	pvars->simulation_time.tv_sec = 0;
	pvars->simulation_time.tv_usec = 0;
	pvars->philos = malloc(sizeof(t_philo) * pvars->nb_philo);
	if (pvars->philos == NULL)
		return ;
	pvars->forks = malloc(sizeof(t_mutexval) * pvars->nb_philo);
	if (pvars->forks == NULL)
		return ;
	pvars->args = malloc(sizeof(t_routine_args) * pvars->nb_philo);
	if (pvars->forks == NULL)
		return ;
	_init_philo(pvars);
}

void	start_simulation(t_philo_vars *pvars)
{
	unsigned int	i;
	t_routine_args	*args;

	gettimeofday(&pvars->simulation_time, NULL);
	i = -1;
	while (++i < pvars->nb_philo)
	{
		args = &pvars->args[i];
		args->id = i;
		args->philo = &pvars->philos[i];
		args->pvars = pvars;
		get_random_name(pvars, args->philo);
		pthread_create(
			&args->philo->thread,
			NULL,
			(void *(*)(void *))routine,
			(void *)args
			);
	}
	_join_threads(pvars);
}

static void	_join_threads(t_philo_vars *pvars)
{
	unsigned int	i;

	i = -1;
	while (++i < pvars->nb_philo)
	{
		pthread_mutex_lock(&pvars->philos[i].is_alive.mutex);
		if (pvars->philos[i].is_alive.val == 1)
		{
			pthread_mutex_unlock(&pvars->philos[i].is_alive.mutex);
			pthread_join(pvars->philos[i].thread, NULL);
		}
		else
			pthread_mutex_unlock(&pvars->philos[i].is_alive.mutex);
	}
}

static void	_exec_parsing(t_philo_vars *pvars, int argc, char **argv)
{
	pvars->exit_status = EXIT_SUCCESS;
	pvars->nb_philo = ft_atoui(argv[1], &pvars->exit_status);
	pvars->t_die = ft_atoui(argv[2], &pvars->exit_status);
	pvars->t_eat = ft_atoui(argv[3], &pvars->exit_status);
	pvars->t_sleep = ft_atoui(argv[4], &pvars->exit_status);
	pvars->nb_meals = 0;
	pvars->infinite_meals = 1;
	pvars->philos = NULL;
	pvars->forks = NULL;
	pvars->args = NULL;
	pvars->a_philo_is_dead.val = 0;
	pthread_mutex_init(&pvars->a_philo_is_dead.mutex, NULL);
	pvars->write.val = 0;
	pthread_mutex_init(&pvars->write.mutex, NULL);
	if (argc == 6)
	{
		pvars->infinite_meals = 0;
		pvars->nb_meals = ft_atoui(argv[5], &pvars->exit_status);
	}
}

static void	_init_philo(t_philo_vars *pvars)
{
	unsigned int	i;
	unsigned int	j;
	t_philo			*philo;

	i = -1;
	while (++i < pvars->nb_philo)
	{
		j = i + 1;
		if (j >= pvars->nb_philo)
			j = 0;
		philo = &pvars->philos[i];
		pthread_mutex_init(&pvars->forks[i].mutex, NULL);
		pvars->forks[i].val = 0;
		philo->l_fork = &pvars->forks[j];
		philo->r_fork = &pvars->forks[i];
		pthread_mutex_init(&pvars->philos[i].meals.mutex, NULL);
		philo->meals.val = 0;
		philo->state = THINKING;
		pthread_mutex_init(&pvars->philos[i].is_alive.mutex, NULL);
		philo->is_alive.val = 1;
		philo->name = NULL;
		philo->roman = NULL;
	}
}
