/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:35:54 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 17:25:51 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	apply_precision(int precision, char **str)
{
	int		i;
	int		len;
	int		j;
	char	*new_str;

	i = 0;
	len = ft_strlen(*str);
	new_str = (char *)malloc(precision + 1);
	if (!new_str)
		return ;
	while (i < precision - len)
		new_str[i++] = '0';
	j = 0;
	while ((*str)[j])
	{
		new_str[i + j] = (*str)[j];
		j++;
	}
	new_str[i + j] = '\0';
	free(*str);
	*str = new_str;
}

static void	add_prefix(const char *prefix, char **str)
{
	int		i;
	int		j;
	char	*new_str;

	new_str = (char *)malloc(ft_strlen(prefix) + ft_strlen(*str) + 1);
	if (!new_str)
		return ;
	i = 0;
	while (prefix[i])
	{
		new_str[i] = prefix[i];
		i++;
	}
	j = 0;
	while ((*str)[j])
	{
		new_str[i + j] = (*str)[j];
		j++;
	}
	new_str[i + j] = '\0';
	free(*str);
	*str = new_str;
}

void	generic_converter(int negative, char type, char **str_num, \
	t_attributes *atr)
{
	if (atr->precision > (int)ft_strlen(*str_num))
		apply_precision(atr->precision, str_num);
	if (atr->plus || negative)
	{
		if (negative)
			add_prefix("-", str_num);
		else
			add_prefix("+", str_num);
	}
	if (atr->space)
		add_prefix(" ", str_num);
	if (atr->hashtag || type == 'p')
	{
		if (type == 'X')
			add_prefix("0X", str_num);
		else
			add_prefix("0x", str_num);
	}
	if (atr->zero_padding && atr->width > (int)ft_strlen(*str_num))
		apply_zero_padding(atr->width, str_num);
	if (atr->width > (int)ft_strlen(*str_num))
		apply_width(atr->left_align, atr->width, str_num);
}
