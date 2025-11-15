/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:10:55 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 18:45:08 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_lowhex(char **res, unsigned int value, t_attributes *atr)
{
	char	*s;

	attributes_annulation(0, value, 'x', atr);
	s = ft_itoa_base(value, 16, "0123456789abcdef");
	if (!s)
		return ;
	generic_converter(0, 'x', &s, atr);
	add_str(s, res);
	free(s);
}

void	handle_uphex(char **res, unsigned int value, t_attributes *atr)
{
	char	*s;

	attributes_annulation(0, value, 'X', atr);
	s = ft_itoa_base(value, 16, "0123456789ABCDEF");
	if (!s)
		return ;
	generic_converter(0, 'X', &s, atr);
	add_str(s, res);
	free(s);
}
