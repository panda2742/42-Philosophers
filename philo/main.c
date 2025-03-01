/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:03:18 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/01 13:13:23 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine()
{
	int	i;

	i = -1;
	while (++i < 10)
	{
		printf("%d\n", i);
		sleep(1);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int			exit_status;
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
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