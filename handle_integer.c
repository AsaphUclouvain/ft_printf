/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:15:44 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/13 23:33:02 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_integer(char **res, int value, t_attributes *atr)
{
	int				sgn;
	char			*s;
	unsigned long long	abs_value;

	sgn = (value < 0);
	attributes_annulation(sgn, value, 'd',  atr);
	abs_value = ft_abs(value);
	s = ft_itoa_base(abs_value, 10, "0123456789");
	generic_converter(sgn, 'd', &s, atr);
	add_str(s, res);
	free(s);
}
