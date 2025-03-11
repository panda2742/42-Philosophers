/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:11:17 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/11 11:13:22 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_vars	pvars;

	if (argc != 5 && argc != 6)
	{
		printf(RED "Error.\n4 or 5 arguments are expected:\n");
		printf("./philo nb_philo t_die t_eat t_sleep [nb_meals]\n" RESET);
		return (EXIT_FAILURE);
	}
	parsing(&pvars, argc, argv);
	if (pvars.exit_status == EXIT_FAILURE)
	{
		printf(RED "Error.\nCheck if the entry is correct and retry. ");
		printf("Unsigned integers are expected.\n" RESET);
		return (EXIT_FAILURE);
	}
	return (pvars.exit_status);
}

