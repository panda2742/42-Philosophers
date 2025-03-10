/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:42:44 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/10 17:04:43 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fr(t_routine_args *args)
{
	const char	*name = args->philo->name;
	const char	*roman = args->philo->roman;

	if (args->philo->state == TAKING_FORK)
		printf("%s%s a pris une fourchette", name, roman);
	if (args->philo->state == EATING)
		printf("%s%s est en train de déguster", name, roman);
	if (args->philo->state == SLEEPING)
		printf("%s%s fait une grosse sieste", name, roman);
	if (args->philo->state == THINKING)
		printf("%s%s gamberge", name, roman);
	if (args->philo->state == DYING)
		printf("%s%s a décidé de nous quitter", name, roman);
}
