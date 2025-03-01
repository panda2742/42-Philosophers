/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:03:18 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/01 22:31:39 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_init_philo(int, char **, t_philo_vars *);

int	main(int argc, char **argv)
{
	t_philo_vars	pvars;

	if (5 != argc && 6 != argc)
	{
		printf(RED "Error.\n  4 or 5 arguments are expected:\n");
		printf("  ./philo nb_philo t_die t_eat t_sleep [nb_meals]\n" RESET);
		return (EXIT_FAILURE);
	}
	_init_philo(argc, argv, &pvars);
	if (EXIT_FAILURE == pvars.exit_status)
	{
		printf(RED "Error.\n  Unsigned int are expected.\n" RESET);
		return (EXIT_FAILURE);
	}
	return (pvars.exit_status);
}

static void	_init_philo(int argc, char **argv, t_philo_vars *pvars)
{
	pvars->exit_status = EXIT_SUCCESS;
	pvars->nb_philo = ft_atoui(argv[1], &pvars->exit_status);
	pvars->t_die = ft_atoui(argv[2], &pvars->exit_status);
	pvars->t_eat = ft_atoui(argv[3], &pvars->exit_status);
	pvars->t_sleep = ft_atoui(argv[4], &pvars->exit_status);
	pvars->infinite_meals = 1;
	pvars->nb_meals = 0;
	pvars->philos = NULL;
	if (argc == 6)
		pvars->infinite_meals = 0;
	if (argc == 6)
		pvars->nb_meals = ft_atoui(argv[5], &pvars->exit_status);
	if (NULL == create_table(pvars))
		return (NULL);
}

int	terminate(int *exit_status, int exit_status_to_set)
{
	*exit_status = exit_status_to_set;
	return (*exit_status);
}