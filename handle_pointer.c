/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:49:25 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/14 05:35:41 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_nil()
{
	char	*nil;
	int	len;

	len = 5;
	nil = (char *)malloc(len + 1);
	if (!nil)
		return (NULL);
	ft_memcpy(nil, "(nil)", len);
	nil[len] = '\0';
	return (nil);
}

void	handle_pointer(char **res, unsigned long ptr, t_attributes *atr)
{
	char	*s;

	attributes_annulation(0, ptr, 'p', atr);
	if (ptr == 0)
		s = ft_nil();
	else
	{
		s = ft_itoa_base(ptr, 16, "0123456789abcdef");
		generic_converter(0, 'p', &s, atr);
	}
	if (!s)
		return ;
	add_str(s, res);
	free(atr);
	free(s);
}
