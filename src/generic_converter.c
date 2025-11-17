/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:35:54 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/17 07:24:34 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	apply_precision(int precision, char **str)
{
	int		i;
	int		j;
	char	*new_str;

	if (precision == 0 && !ft_strncmp(*str, "0", ft_strlen(*str)))
	{
		free(*str);
		*str = ft_calloc(1, 1);
	}
	i = 0;
	new_str = (char *)malloc(precision + 1);
	if (!new_str)
		return ;
	j = precision - ft_strlen(*str);
	while (i < j)
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
	int		len_prefix;
	int		len_str;
	char	*new_str;

	len_str = ft_strlen(*str);
	len_prefix = ft_strlen(prefix);
	new_str = (char *)malloc(len_str + len_prefix + 1);
	if (!new_str)
		return ;
	i = 0;
	while ((*str)[i] && ft_strchr(" +", (*str)[i]))
	{
		new_str[i] = (*str)[i];
		i++;
	}
	ft_memcpy(new_str + i, prefix, len_prefix);
	ft_memcpy(new_str + i + len_prefix, *str + i, len_str - i);
	new_str[len_str + len_prefix] = '\0';
	free(*str);
	*str = new_str;
}

static void	add_sign(const char *sign, char **str)
{
	int		i;
	int		j;
	char	*new_str;

	new_str = (char *)malloc(ft_strlen(sign) + ft_strlen(*str) + 1);
	if (!new_str)
		return ;
	i = 0;
	while (sign[i])
	{
		new_str[i] = sign[i];
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

void	generic_converter(int negative, char type, char **str_num,\
	t_attributes *atr)
{
	if (atr->precision == 0 || atr->precision > (int)ft_strlen(*str_num))
		apply_precision(atr->precision, str_num);
	if (atr->plus || negative)
	{
		if (negative)
			add_sign("-", str_num);
		else
			add_sign("+", str_num);
	}
	if (atr->space)
		add_sign(" ", str_num);
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
