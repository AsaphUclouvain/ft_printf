/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:26:12 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/08 13:11:23 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_null(int precision)
{
	char	*null;
	int		len;

	if (precision < 6)
		return (ft_calloc(1, 1));
	len = ft_min(6, precision);
	null = (char *)malloc(len + 1);
	if (!null)
		return (NULL);
	ft_memcpy(null, "(null)", len);
	null[len] = '\0';
	return (null);
}

char	*apply_precision(char *new_str, int precision)
{
	int		i;
	int		len;
	char	*s;

	if (!new_str)
		return (ft_null(precision));
	len = ft_min(ft_strlen(new_str), precision);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, new_str, len);
	s[len] = '\0';
	return (s);
}

void	add_str(char *new_str, char **res)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)malloc(ft_strlen(*res) + ft_strlen(new_str) + 1);
	if (!tmp)
		return ;
	i = 0;
	while (*res[i])
	{
		tmp[i] = *res[i];
		i++;
	}
	j = 0;
	while (new_str[j])
	{
		tmp[i + j] = new_str[j];
		j++;
	}
	tmp[i + j] = '\0';
	free(*res);
	*res = tmp;
}

void	handle_string(char *str, char **res, char *new_str, t_attributes *atr)
{
	char	*s;
	int		len;

	if (!atr)
		return ;
	if (atr->precision >= 0)
		s = apply_precision(new_str, atr->precision);
	if (!s)
		return ;
	len = ft_strlen(s);
	if (atr->width <= len)
		return (add_str(s, res));
	if (atr->left_align)
	{
		add_str(s, res);
		add_char(res, 32, atr->width - len);
	}
	else
	{
		add_char(res, atr->width - len);
		add_str(s, res);
	}
	free(s);
	free(atr);
}
