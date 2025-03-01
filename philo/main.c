/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:03:18 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/01 11:51:45 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	exit_status;

	(void)argc;
	(void)argv;
	exit_status = EXIT_SUCCESS;
	return (exit_status);
}

int	terminate(int *exit_status, int exit_status_to_set)
{
	*exit_status = exit_status_to_set;
	return (*exit_status);
}