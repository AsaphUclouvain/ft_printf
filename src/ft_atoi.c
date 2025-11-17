/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 00:45:20 by anzongan          #+#    #+#             */
/*   Updated: 2025/10/26 17:07:08 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\f' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sgn;

	while (*nptr && ft_isspace(*nptr))
		nptr++;
	sgn = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sgn = -1;
		nptr++;
	}
	res = 0;
	while (*nptr && '0' <= *nptr && *nptr <= '9')
		res = res * 10 + (*nptr++ - '0');
	return (sgn * res);
}
