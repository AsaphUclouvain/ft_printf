/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:03:30 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 18:43:51 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_unsigned_int(char **res, unsigned int value, t_attributes *atr)
{
	char	*s;

	attributes_annulation(0, value, 'u', atr);
	s = ft_itoa_base(value, 10, "0123456789");
	if (!s)
		return ;
	generic_converter(0, 'u', &s, atr);
	add_str(s, res);
	free(s);
}
