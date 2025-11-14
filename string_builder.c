/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:15:30 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/14 03:12:38 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(const char *str, char *sp, char **res, va_list *ap)
{
	t_attributes	*atr;

	atr = set_attributes(str, wp_builder(str, ap));
	if (!atr)
		return (-1);
	if (!sp)
		return (1);
	else if (*sp == '%')
		handle_percent(res);
	else if (*sp == 'i' || *sp == 'd')
		handle_integer(res, va_arg(*ap, int), atr);
	else if (*sp == 'u')
		handle_unsigned_int(res, va_arg(*ap, unsigned int), atr);
	else if (*sp == 'x')
		handle_lowhex(res, va_arg(*ap, unsigned int), atr);
	else if (*sp == 'X')
		handle_uphex(res, va_arg(*ap, unsigned int), atr);
	else if (*sp == 'p')
		handle_pointer(res, (unsigned long)va_arg(*ap, void *), atr);
	else if (*sp == 'c')
		handle_char(res, va_arg(*ap, int), atr);
	else if (*sp == 's')
		handle_string(res, va_arg(*ap, char *), atr);
	return (sp - str + 2);
}

int	handle_format(const char *str, char **res, va_list *ap)
{
	char	*sp;
	int	star_width;
	int	star_precision;//sp, star_width and star_precision will be in a structure

	if (!str || !res || !ap)
		return (-1);
	if (valid_chars(str) < 0 || valid_order(str) < 0)
		return (1);//go to the next char in the caller function
	sp = first_specifier(str);
	return (handle_specifier(str, sp, res, ap));
}

int	char_sequence(unsigned int len, const char *str, char **res)
{
	int		i;
	int		j;
	char	*tmp;

	if (!res || !str)
		return (-1);
	tmp = (char *)malloc(ft_strlen(*res) + len + 1);
	if (!tmp)
		return (-1);
	i = 0;
	while ((*res)[i])
	{
		tmp[i] = (*res)[i];
		i++;
	}
	j = 0;
	while (j < len)
	{
		tmp[i + j] = str[j];
		j++;
	}
	tmp[i + j] = '\0';
	free(*res);
	*res = tmp;
	return (j);
}

int	string_builder(const char *format, char **res, va_list *ap)
{
	int	i;
	int	covered;

	i = 0;
	while (format[i])
	{
		covered = 0;
		if (format[i] == '%')
			covered = handle_format(format + i + 1, res, ap);
		else
		{
			while (format[i + covered] && format[i + covered] != '%')
				covered++;
			if (covered > 0)
				covered = char_sequence(covered, format + i, res);
		}
		if (covered < 0)
			return (-1);
		//printf("%d -- %c -- %s\n", covered, format[i], *res);
		i += covered;
	}
	return (i);
}
