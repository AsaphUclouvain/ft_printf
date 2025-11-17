/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:07:54 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 17:42:10 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

long	ft_abs(int val)
{
	if (val < 0)
		return (-(long)val);
	return ((long)val);
}

void	write_spaces(int width)
{
	while (width > 0)
	{
		write(1, " ", 1);
		width--;
	}
}
