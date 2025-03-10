/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_roman.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:44:45 by ehosta            #+#    #+#             */
/*   Updated: 2025/03/10 16:45:54 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	_roman_size(int vals[13], char *chars[13], size_t nb);
static void		_put_roman(char *chars[13], int vals[13], int nb, char *res);
static size_t	_ft_strlen(const char *s);

char	*int_to_roman(size_t nb)
{
	static char		*chars[13] = {
		"I\0", "IV", "V\0", "IX", "X\0", "XL",
		"L\0", "XC", "C\0", "CD", "D\0", "CM", "M\0"
	};
	static int		vals[13] = {
		1, 4, 5, 9, 10, 40,
		50, 90, 100, 400, 500, 900, 1000
	};
	char			*res;
	size_t			len;

	len = _roman_size(vals, chars, nb);
	res = malloc(sizeof(char) * (len + 2));
	if (!res)
		return (malloc(sizeof(char)));
	res[0] = ' ';
	res[len] = 0;
	_put_roman(chars, vals, nb, res + 1);
	return (res);
}

static size_t	_roman_size(int vals[13], char *chars[13], size_t nb)
{
	size_t	res;
	int		i;
	int		div;

	res = 0;
	i = 12;
	while (nb > 0)
	{
		div = nb / vals[i];
		nb = nb % vals[i];
		while (div--)
			res += _ft_strlen(chars[i]);
		i--;
	}
	return (res);
}

static void	_put_roman(char *chars[13], int vals[13], int nb, char *res)
{
	int		i;
	int		k;
	int		div;

	i = 12;
	k = 0;
	while (nb > 0)
	{
		div = nb / vals[i];
		nb = nb % vals[i];
		while (div--)
		{
			res[k++] = chars[i][0];
			if (chars[i][1]) res[k++] = chars[i][1];
		}
		i--;
	}
}

static size_t	_ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}