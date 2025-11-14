/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:26:12 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/14 05:00:27 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	if (new_str == NULL)//in this case we return the character (null)
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
	len = ft_min(ft_strlen(new_str), precision);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, new_str, len);
	s[len] = '\0';
	return (s);
}

void	handle_string(char **res, char *new_str, t_attributes *atr)
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
		add_str(s, res);
	else if (atr->left_align)
	{
		add_str(s, res);
		add_char(atr->width - len, 32, res);
	}
	else
	{
		add_char(atr->width - len, 32, res);
		add_str(s, res);
	}
	free(s);
	free(atr);
}
