/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:15:30 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/06 23:35:29 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"


int	isspecifier(char c)
{
	return (ft_strchr("cspdiuxX%", c) != NULL);
}

char	*first_specifier(const char *str)
{
	int	i;

	i  = 0;
	while (str[i])
	{
		if (isspecifier(str[i]))
			return ((char *)s + i);
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
	if (str[i] == '*' &&  either == i)
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
		return (-1);
	return (i);
}

int	valid_chars(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && !isspecifier(str[i]))
	{
		if (!ft_strchr("0123456789# -+.*", str[i]))
			return (-1);
		i++;
	}
	if (!str[i])
		return (-1);
	return (i);
}

int	wp_builder(const char *str, va_list *ap)
{
	int	i;
	int	w;
	int	p;
	width_precision	*wp;

	i = 0;
	w = 0;
	p = 0;
	while (str[i] && ft_strchr("0#-+ ", str[i]))
		i++;
	if (str[i] == '*')
		w = va_arg(*ap, int);
	i = 0;
	while (str[i] && ft_strchr("0#-+ *123456789", str[i]))
		i++;
	if (str[i] == '.' && str[i + 1] == '*')
		p = va_arg(*ap, int);
	wp = (width_precision *)malloc(sizeof(width_precision));
	if (!wp)
		return (NULL);
	wp->width = w;
	wp->precision = p;
	return (wp);
}

int	handle_specifier(const char *str, char *sp, char **res, va_list *ap)
{
	width_precision	*wp;

	wp = wp_builder(str, ap);
	if (!sp)
		return (1);
	if (*sp == '%')
		handle_percent(str, res);
	if (*sp == 'i' || *sp == 'd')
		handle_integer(str, res, va_arg(*ap, int), wp);
	if (*sp == 'u')
		handle_unsigned_int(str, res, va_arg(*ap, unsigned int), wp);
	if (*sp == 'x')
		handle_lowhex(str, res, va_arg(*ap, unsigned int), wp);
	if (*sp == 'X')
		handle_uphex(str, res, va_arg(*ap, unsigned int), wp);
	if (*sp == 'p')
		handle_pointer(str, res, va_arg(*ap, void *), wp);
	if (*sp == 'c')
		handle_char(str, res, va_arg(*ap, int), wp);
	if (*sp == 's')
		handle_string(str, res, va_arg(*ap, char *), wp);
	return (sp - str);
}

int	handle_format(const char *str, char **res, va_list *ap)
{
	char	*sp;
	int	star_width;
	int	star_precision;//sp, star_width and star_precision will be in a structure

	if (!str || !res || !ap)
		return (-1);
	if (valid_chars(str) < 0 || valid_order(str) < 0)
		return (1);//go to the next char
	sp = first_specifier(str);
	return (handle_specifiers(str, sp, res, ap));
}

int	char_sequence(unsigned int len, const char *str, char **res)
{
	int		i;
	int		j;
	char	*tmp;

	if (!res || !str)
		return (NULL);
	tmp = (char *)malloc(ft_strlen(*res) + len + 1);
	if (!tmp)
		return (-1);
	i = 0;
	while (*res[i])
	{
		tmp[i] = *res[i];
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
	covered = 0;
	while (format[i])
	{
		if (format[i] == '%')
			covered = handle_format(&format[i], res, ap);
		else
		{
			while (format[i] && format[i] != '%')
				covered++;
			covered = char_sequence(covered, &format[i], res);
		}
		if (covered < 0)
			return (-1);
		i += covered;
	}
	return (i);
}
