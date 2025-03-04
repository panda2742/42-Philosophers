/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:03:18 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/04 13:27:05 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void			_init_philo(int, char **, t_philo_vars *);
static unsigned int	_ft_atoui(const char *nptr, int *exit_code);

int	main(int argc, char **argv)
{
	t_philo_vars	pvars;

	if (argc != 5 && argc != 6)
	{
		printf(RED "Error.\n  4 or 5 arguments are expected:\n");
		printf("  ./philo nb_philo t_die t_eat t_sleep [nb_meals]\n" RESET);
		return (EXIT_FAILURE);
	}
	_init_philo(argc, argv, &pvars);
	if (pvars.exit_status == EXIT_FAILURE)
	{
		printf(RED "Error.\n  Errors occured.\n" RESET);
		return (EXIT_FAILURE);
	}
	return (pvars.exit_status);
}

static void	_init_philo(int argc, char **argv, t_philo_vars *pvars)
{
	pvars->exit_status = EXIT_SUCCESS;
	pvars->nb_philo = _ft_atoui(argv[1], &pvars->exit_status);
	pvars->exit_status = EXIT_SUCCESS;
	pvars->t_die = _ft_atoui(argv[2], &pvars->exit_status);
	pvars->exit_status = EXIT_SUCCESS;
	pvars->t_eat = _ft_atoui(argv[3], &pvars->exit_status);
	pvars->t_sleep = _ft_atoui(argv[4], &pvars->exit_status);
	pvars->nb_meals = 0;
	pvars->philos = NULL;
	if (argc == 6)
	{
		pvars->infinite_meals = 0;
		pvars->nb_meals = _ft_atoui(argv[5], &pvars->exit_status);
	}
	if (create_table(pvars) == NULL)
		return ;
}

int	terminate(int *exit_status, int exit_status_to_set)
{
	*exit_status = exit_status_to_set;
	return (*exit_status);
}

static unsigned int	_ft_atoui(const char *nptr, int *exit_code)
{
	int	res;

	res = 0;
	while (*nptr && *nptr < 32)
		nptr++;
	while (*nptr)
	{
		if (*nptr < '0' || *nptr > '9')
		{
			*exit_code = EXIT_FAILURE;
			break ;
		}
		if ((res * 10 + *nptr - '0') / 10 != res)
		{
			*exit_code = EXIT_FAILURE;
			break ;
		}
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res);
}
