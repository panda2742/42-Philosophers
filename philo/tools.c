/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:54:35 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/01 21:37:04 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	ft_atoui(const char *nptr, int *exit_code)
{
	int	res;

	res = 0;
	while (*nptr && *nptr < 32)
		nptr++;
	while (*nptr)
	{
		if (*nptr <= '0' || *nptr >= '9')
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
