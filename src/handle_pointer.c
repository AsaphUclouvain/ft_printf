/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:49:25 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 23:42:40 by anzongan         ###   ########.fr       */
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

void	handle_pointer(int *bytes_read,\
	unsigned long long ptr, t_attributes *atr)
{
	char	*s;

	attributes_annulation(0, ptr, 'p', atr);
	if (ptr == 0)
	{
		s = ft_nil();
		if (atr->width > (int)ft_strlen(s))
			apply_width(atr->left_align, atr->width, &s);
	}
	else
	{
		s = ft_itoa_base(ptr, 16, "0123456789abcdef");
		generic_converter(0, 'p', &s, atr);
	}
	if (!s)
		return ;
	ft_putstr_fd(s, 1);
	*bytes_read += ft_strlen(s);
	free(s);
}
