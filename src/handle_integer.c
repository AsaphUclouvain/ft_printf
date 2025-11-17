/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:15:44 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 23:39:44 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	handle_integer(int *bytes_read,\
	int value, t_attributes *atr)
{
	int		sgn;
	char	*s;
	long	abs_value;

	sgn = (value < 0);
	abs_value = ft_abs(value);
	attributes_annulation(sgn, abs_value, 'd', atr);
	s = ft_itoa_base(abs_value, 10, "0123456789");
	if (!s)
		return ;
	generic_converter(sgn, 'd', &s, atr);
	ft_putstr_fd(s, 1);
	*bytes_read += ft_strlen(s);
	free(s);
}
