/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes_extractor3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 00:23:45 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 16:58:45 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	attributes_annulation(int negative, unsigned long long value, \
	char type, t_attributes *atr)
{
	if (atr->precision >= 0 || atr->left_align)
		atr->zero_padding = 0;
	if (atr->plus || negative || (type != 'd' && type != 'i'))
		atr->space = 0;
	if (type != 'i' && type != 'd')
		atr->plus = 0;
	if (type == 'x' || type == 'X')
	{
		if (value == 0)
			atr->hashtag = 0;
	}
	else
		atr->hashtag = 0;
}

t_attributes	*set_attributes(const char *str, t_width_precision *wp)
{
	t_attributes	*atr;

	atr = (t_attributes *)malloc(sizeof(t_attributes));
	if (!atr)
		return (NULL);
	atr->width = ft_max(width(str), wp->width);
	atr->precision = ft_max(precision(str), wp->precision);
	atr->left_align = left_align(str);
	atr->zero_padding = zero_padding(str);
	atr->hashtag = hashtag(str);
	atr->plus = plus(str);
	atr->space = space(str);
	free(wp);
	return (atr);
}
