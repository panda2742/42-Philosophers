/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:40:07 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/02 19:55:00 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philo(t_philo_vars *pvars, unsigned int id, t_philo *left_philo, t_philo *right_philo)
{
	t_philo	*philo;
	
	philo = malloc(sizeof(t_philo));
	if (NULL == philo)
	{
		pvars->exit_status = EXIT_FAILURE;
		printf(RED "Error.\n  Memory allocation failed.\n" RESET);
		return (NULL);
	}
	if (0 != pthread_create(&philo->thread, NULL, (void *(*)(void *))&routine, (void *)pvars))
	{
		pvars->exit_status = EXIT_FAILURE;
		printf(RED "Error.\n  Thread (on philosopher) creation failed.\n" RESET);
		return (NULL);
	}
	philo->id = id;
	philo->left = left_philo;
	philo->right = right_philo;
	philo->fork = create_fork(pvars, philo);
	if (NULL == philo->fork)
		return (NULL);
	pthread_join(philo->thread, NULL);
	return (philo);
}

t_pfork	*create_fork(t_philo_vars *pvars, t_philo *philo)
{
	t_pfork	*fork;

	fork = malloc(sizeof(t_pfork));
	if (NULL == fork)
	{
		pvars->exit_status = EXIT_FAILURE;
		printf(RED "Error.\n  Memory allocation failed.\n" RESET);
		return (NULL);
	}
	if (0 != pthread_mutex_init(&fork->mutex, NULL))
	{
		pvars->exit_status = EXIT_FAILURE;
		printf(RED "Error.\n  Mutex (on fork) creation failed.\n" RESET);
		return (NULL);
	}
	fork->philo = philo;
	fork->cur_user = NULL;
	return (fork);
}

t_philo	**create_table(t_philo_vars *pvars)
{
	t_philo			*left_philo;
	t_philo			*right_philo;
	unsigned int	i;

	left_philo = create_philo(pvars, 1, NULL, NULL);
	if (NULL == left_philo)
		return (NULL);
	pvars->philos = &left_philo;
	right_philo = NULL;
	printf("%p\n", *pvars->philos);
	i = 1;
	while (++i <= pvars->nb_philo)
	{
		right_philo = create_philo(pvars, i, left_philo, NULL);
			return (NULL);
		left_philo->right = right_philo;
		if (NULL == right_philo)
			return (NULL);
		left_philo = right_philo;
	}
	return (pvars->philos);
}
