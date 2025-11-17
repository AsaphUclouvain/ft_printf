/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:09:14 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/16 00:01:41 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(int *bytes_read, int c, t_attributes *atr)
{
	int	w;

	w = 0;
	attributes_annulation(0, c, 'c', atr);
	if (atr && atr->width)
		w = atr->width;
	if (w <= 1)
		*bytes_read += write(1, &c, 1);
	else
	{
		if (atr->left_align)
		{
			write(1, &c, 1);
			write_spaces(w - 1);
		}
		else
		{
			write_spaces(w - 1);
			write(1, &c, 1);
		}
		*bytes_read += w;
	}
}
