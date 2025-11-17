/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_builder_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:46:37 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 17:41:21 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	isspecifier(char c)
{
	return (ft_strchr("cspdiuxX%", c) != NULL);
}

char	*first_specifier(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (isspecifier(str[i]))
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

int	valid_order(const char *str)
{
	int	i;
	int	either;

	i = 0;
	while (str[i] && ft_strchr("0# -+", str[i]))
		i++;
	either = i;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == '*' && either == i)
		i++;
	if (str[i] == '.')
	{
		i++;
		either = i;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		if (str[i] == '*' && either == i)
			i++;
	}
	if (!str[i])
		return (-1);
	if (!isspecifier(str[i]))
		return (-2);
	return (i);
}

t_width_precision	*wp_builder(const char *str, va_list *ap)
{
	int					i;
	int					w;
	int					p;
	t_width_precision	*wp;

	i = 0;
	w = 0;
	p = -1;
	while (str[i] && ft_strchr("0#-+ ", str[i]))
		i++;
	if (str[i] == '*')
		w = va_arg(*ap, int);
	i = 0;
	while (str[i] && ft_strchr("0#-+ *123456789", str[i]))
		i++;
	if (str[i] == '.' && str[i + 1] == '*')
		p = va_arg(*ap, int);
	wp = (t_width_precision *)malloc(sizeof(t_width_precision));
	if (!wp)
		return (NULL);
	wp->width = w;
	wp->precision = p;
	return (wp);
}
