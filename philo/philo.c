/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:40:07 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/04 09:40:53 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo_vars *pvars)
{
	(void)pvars;
	write(1, "Living\n", 8);
	for (int i = 0; i < 1000000000 ; i++)
	{
		
	}
	write(1, "Dying\n", 7);
	return (NULL);
}

t_philo	*create_philo(t_philo_vars *pvars, unsigned int id, t_philo *left_philo, t_philo *right_philo)
{
	t_philo	*philo;
	
	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
	{
		pvars->exit_status = EXIT_FAILURE;
		printf(RED "Error.\n  Memory allocation failed.\n" RESET);
		return (NULL);
	}
	if (pthread_create(&philo->thread, NULL, (void *(*)(void *))&routine, (void *)pvars) != 0)
	{
		pvars->exit_status = EXIT_FAILURE;
		printf(RED "Error.\n  Thread (on philosopher) creation failed.\n" RESET);
		return (NULL);
	}
	philo->id = id;
	philo->left = left_philo;
	philo->right = right_philo;
	philo->fork = create_fork(pvars, philo);
	if (philo->fork == NULL)
		return (NULL);
	return (philo);
}

t_pfork	*create_fork(t_philo_vars *pvars, t_philo *philo)
{
	t_pfork	*fork;

	fork = malloc(sizeof(t_pfork));
	if (fork == NULL)
	{
		pvars->exit_status = EXIT_FAILURE;
		printf(RED "Error.\n  Memory allocation failed.\n" RESET);
		return (NULL);
	}
	if (pthread_mutex_init(&fork->mutex, NULL) != 0)
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
	t_philo			*philo;
	unsigned int	i;

	left_philo = create_philo(pvars, 1, NULL, NULL);
	if (left_philo != 0)
		return (NULL);
	pvars->philos = &left_philo;
	right_philo = NULL;
	printf("%p\n", *pvars->philos);
	i = 1;
	printf("nb philos: %d\n", pvars->nb_philo);
	while (++i <= pvars->nb_philo)
	{
		right_philo = create_philo(pvars, i, left_philo, NULL);
		left_philo->right = right_philo;
		if (right_philo == NULL)
			return (NULL);
		left_philo = right_philo;
	}
	philo = *pvars->philos;
	printf("philo %p\n", philo);
	philo = philo->right;
	while (philo)
	{
		printf("philo %p\n", philo);
		philo = philo->right;
	}
	return (pvars->philos);
}
