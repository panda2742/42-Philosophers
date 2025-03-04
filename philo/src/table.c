/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:40:07 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/04 16:53:00 by ehosta           ###   ########.fr       */
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

t_philo	*create_table(t_philo_vars *pvars)
{
	unsigned int	i;
	unsigned int	j;
	t_philo			philo;

	pvars->philos = malloc(sizeof(t_philo) * pvars->nb_philo);
	if (pvars->philos == NULL)
	{
		pvars->exit_status = EXIT_FAILURE;
		printf(RED "Error.\n  Memory allocation failed.\n" RESET);
		return (NULL);
	}
	pvars->forks = malloc(sizeof(t_pfork) * pvars->nb_philo);
	if (pvars->forks == NULL)
	{
		pvars->exit_status = EXIT_FAILURE;
		printf(RED "Error.\n  Memory allocation failed.\n" RESET);
		return (NULL);
	}
	i = -1;
	while (++i < pvars->nb_philo)
	{
		j = i + 1;
		if (j >= pvars->nb_philo)
			j = 0;
		pvars->philos[i].r_fork = &pvars->forks[i];
		pvars->philos[j].l_fork = &pvars->forks[i];
		pvars->forks[i].is_being_used = 0;
	}
	i = -1;
	while (++i < pvars->nb_philo)
	{
		philo = pvars->philos[i];
		printf("%p <- [%d] %p ->\n", philo.l_fork, i, philo, philo.r_fork);
	}
	return (&pvars->philos[0]);
}
