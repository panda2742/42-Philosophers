/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:03:18 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/10 16:18:35 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_vars	pvars;

	if (argc != 5 && argc != 6)
	{
		printf(RED "Error.\n  4 or 5 arguments are expected:\n");
		printf("  ./philo nb_philo t_die t_eat t_sleep [nb_meals]\n" RESET);
		return (EXIT_FAILURE);
	}
	
	create_table(&pvars, argc, argv);
	start_simulation(&pvars);
	clear_table(&pvars);
	
	if (pvars.exit_status == EXIT_FAILURE)
	{
		printf(RED "Error.\n  Errors occured.\n" RESET);
		return (EXIT_FAILURE);
	}
	return (pvars.exit_status);
}
