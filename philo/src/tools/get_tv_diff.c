/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tv_diff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:52:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/10 15:52:33 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_tv_diff(t_timestamp tv1, t_timestamp tv2)
{
	long long	secs;
	long long	usecs;
	long long	res;

	if (tv1.tv_sec == 0)
		gettimeofday(&tv1, NULL);
	if (tv2.tv_sec == 0)
		gettimeofday(&tv2, NULL);
	secs = tv1.tv_sec - tv2.tv_sec;
	usecs = tv1.tv_usec - tv2.tv_usec;
	res = secs * 1000 + usecs / 1000;
	return (res);
}
