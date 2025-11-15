/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:49:25 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 18:45:20 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_nil(void)
{
	char	*nil;
	int		len;

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
	free(s);
}
