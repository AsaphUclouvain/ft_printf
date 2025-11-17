/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:26:12 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/16 00:03:27 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_null(int precision)
{
	char	*null;
	int		len;

	if (0 <= precision && precision < 6)
		return (ft_calloc(1, 1));
	len = 6;
	null = (char *)malloc(len + 1);
	if (!null)
		return (NULL);
	ft_memcpy(null, "(null)", len);
	null[len] = '\0';
	return (null);
}

static char	*apply_precision_str(int precision, char *new_str)
{
	int		len;
	char	*s;

	if (new_str == NULL)
		return (ft_null(precision));
	if (precision < 0)
	{
		len = ft_strlen(new_str);
		s = (char *)malloc(len + 1);
		if (!s)
			return (NULL);
		ft_memcpy(s, new_str, len);
		s[len] = '\0';
		return (s);
	}
	len = ft_min((int)ft_strlen(new_str), precision);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, new_str, len);
	s[len] = '\0';
	return (s);
}

void	handle_string(int *bytes_read,\
	char *new_str, t_attributes *atr)
{
	char	*s;
	int		len;

	attributes_annulation(0, 0, 's', atr);
	if (!atr)
		return ;
	s = apply_precision_str(atr->precision, new_str);
	if (!s)
		return ;
	len = ft_strlen(s);
	if (atr->width <= len)
		ft_putstr_fd(s, 1);
	else if (atr->left_align)
	{
		ft_putstr_fd(s, 1);
		write_spaces(atr->width - len);
	}
	else
	{
		write_spaces(atr->width - len);
		ft_putstr_fd(s, 1);
	}
	*bytes_read += ft_max(len, atr->width);
	free(s);
}
