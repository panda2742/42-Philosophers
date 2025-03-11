/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:11:43 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/11 11:12:26 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(t_philo_vars *pvars, int argc, char **argv)
{
	pvars->exit_status = EXIT_SUCCESS;
	pvars->nb_philo = ft_atoui(argv[1], &pvars->exit_status);
	pvars->t_die = ft_atoui(argv[2], &pvars->exit_status);
	pvars->t_eat = ft_atoui(argv[3], &pvars->exit_status);
	pvars->t_sleep = ft_atoui(argv[4], &pvars->exit_status);
	pvars->nb_meals = 0;
	pvars->infinite_meals = 1;
	if (argc == 6)
	{
		pvars->infinite_meals = 0;
		pvars->nb_meals = ft_atoui(argv[5], &pvars->exit_status);
	}
}
