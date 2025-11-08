/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:09:14 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/08 12:52:36 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_char(char **res, int c, int rep)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)malloc(ft_strlen(*res) + rep + 1);
	if (!tmp)
		return ;
	i = 0;
	while (*res[i])
	{
		tmp[i] = *res[i];
		i++;
	}
	free(*res);
	j = 0;
	while (str[j] && j < rep)
	{
		tmp[i + j] = c;
		j++;
	}
	tmp[i + j] = '\0';
	res = tmp;
}

void	handle_char(char *str, char **res, int c, t_attributes* atr)
{
	int		w;
	char	*tmp;

	w = 0;
	if (atr && atr->width)
		w = atr->width;
	if (w <= 1)
		add_char(res, c, 1);
	else
	{
		if (atr->left_align)
		{
			add_char(res, c, 1);
			add_char(res, 32, w - 1);
		}
		else
		{
			add_char(res, 32, w - 1);
			add_char(res, c, 1);
		}		
	}
	free(atr);
}
