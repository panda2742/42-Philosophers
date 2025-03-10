/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:43:11 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/10 17:09:27 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	_name_owners(t_philo_vars *pvars, t_philo *ref, char *name);

void	get_random_name(t_philo_vars *pvars, t_philo *ref)
{
	static char	*names[8] = {
		"Balthazar", "Bernard", "Maurice", "Rodolphe",
		"Elodie", "Ghislaine", "Henriette", "Philomène"
	};
	static int	i = 0;
	t_timestamp	tv;
	char		*name;
	size_t		owners;

	gettimeofday(&tv, NULL);
	i += tv.tv_usec % 8;
	if (i >= 8)
		i %= 8;
	name = names[i];
	owners = _name_owners(pvars, ref, name);
	ref->name = name;
	ref->roman = int_to_roman(owners + 1);
	i++;
}

static size_t	_name_owners(t_philo_vars *pvars, t_philo *ref, char *name)
{
	size_t			res;
	unsigned int	i;

	res = 0;
	i = -1;
	while (++i < pvars->nb_philo)
	{
		if (&pvars->philos[i] == ref)
			continue ;
		if (pvars->philos[i].name == name)
			res++;
	}
	return (res);
}
