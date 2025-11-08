/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:21:24 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/08 16:27:58 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	valid_base(const char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	num_len(unsigned long long num, int base_len)
{
	int	len;

	len = (num == 0);
	while (num)
	{
		num /= base_len;
		len++;
	}
	return (len);
}

void	str_reverse(char *str)
{
	int		right;
	int		left;
	char	tmp;

	left = 0;
	right = ft_strlen(str) - 1;
	while (left < right)
	{
		tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}
}

char	*itoa_base(unsigned long long num, int base_len, const char *base)
{
	char	*str_num;
	int		len;
	int		i;

	if (!valid_base(base) || base_len != ft_strlen(base))
		return (NULL);
	len = num_len(num, base_len);
	str_num = (char *)malloc(len + 1);
	if (!str_num)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str_num[i] = base[num % base_len];
		num /= base_len;
		i++;
	}
	str_num[i] = '\0';
	str_reverse(str_num);
	return (str_num);
}

void	generic_converter(int negative, char type, char *str_num, t_attributes *atr)
{
	if (atr->precision > ft_strlen(str_num))
		apply_precision(atr->precision, &str_num);
	if (atr->plus || negative)
	{
		if (negative)
			add_prefix("-", &str_num);
		else
			add_prefix("+", &str_num);
	}
	if (atr->space)
		add_prefix(" ", &str_num);
	if (atr->hashtag || type == 'p')
	{
		if (type == 'X')
			add_prefix("0X", &str_num);
		else
			add_prefix("0x", &str_num);
	}
	if (atr->zero_padding && atr->width > ft_strlen(str_num))
		apply_zero_padding(atr->width, &str_num);
	if (atr->width > ft_strlen(str_num))
		apply_width(atr->left_align, &str_num);
}
