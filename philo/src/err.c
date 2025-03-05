/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:33:53 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/05 09:35:33 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ret_malloc_error(t_philo_vars *pvars)
{
	pvars->exit_status = EXIT_FAILURE;
	printf(RED "Error.\n  Memory allocation failed.\n" RESET);
	return (NULL);
}
