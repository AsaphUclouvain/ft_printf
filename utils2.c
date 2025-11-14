/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:11:14 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/11 15:34:26 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_abs(int val)
{
	if (val < 0)
		return (-(long)val);
	return ((long)val);
}

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (INT_MAX / nmemb < size)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
