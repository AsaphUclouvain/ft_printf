/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:03:30 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 23:46:04 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	handle_unsigned_int(int *bytes_read,\
	unsigned int value, t_attributes *atr)
{
	char	*s;

	attributes_annulation(0, value, 'u', atr);
	s = ft_itoa_base(value, 10, "0123456789");
	if (!s)
		return ;
	generic_converter(0, 'u', &s, atr);
	ft_putstr_fd(s, 1);
	*bytes_read += ft_strlen(s);
	free(s);
}
