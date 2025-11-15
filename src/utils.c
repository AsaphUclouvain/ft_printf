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

void	add_char(int rep, int c, char **res)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)malloc(ft_strlen(*res) + rep + 1);
	if (!tmp)
		return ;
	i = 0;
	while ((*res)[i])
	{
		tmp[i] = (*res)[i];
		i++;
	}
	j = 0;
	while (j < rep)
	{
		tmp[i + j] = c;
		j++;
	}
	tmp[i + j] = '\0';
	free(*res);
	*res = tmp;
}

void	add_str(char *new_str, char **res)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)malloc(ft_strlen(*res) + ft_strlen(new_str) + 1);
	if (!tmp)
		return ;
	i = 0;
	while ((*res)[i])
	{
		tmp[i] = (*res)[i];
		i++;
	}
	j = 0;
	while (new_str[j])
	{
		tmp[i + j] = new_str[j];
		j++;
	}
	tmp[i + j] = '\0';
	free(*res);
	*res = tmp;
}
