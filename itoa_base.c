/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:21:24 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/11 16:23:53 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	valid_base(const char *base)
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

static int	num_len(unsigned long long num, int base_len)
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

static void	str_reverse(char *str)
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

char	*ft_itoa_base(unsigned long long num, int base_len, const char *base)
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
