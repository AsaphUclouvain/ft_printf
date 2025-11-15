/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:09:14 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 18:44:40 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(char **res, int c, t_attributes *atr)
{
	int		w;

	w = 0;
	attributes_annulation(0, c, 'c', atr);
	if (atr && atr->width)
		w = atr->width;
	if (w <= 1)
		add_char(1, c, res);
	else
	{
		if (atr->left_align)
		{
			add_char(1, c, res);
			add_char(w - 1, 32, res);
		}
		else
		{
			add_char(w - 1, 32, res);
			add_char(1, c, res);
		}
	}
}
