/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:15:30 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/04 23:47:49 by anzongan         ###   ########.fr       */
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

int	handle_specifier(const char *str, char **res, va_list *ap)
{
	char	*sp;
	int	star_width;
	int	star_precision;//sp, star_width and star_precision will be in a structure

	if (!str || !res || !ap)
		return (-1);
	if (valid_chars(str) < 0 || valid_order(str) < 0)
		return (1);//go to the next char
	sp = first_specifier(str);
	if (!sp)
		return (1);
	if (*sp == '%')
		handle_percent(str, res);
	else if (*sp == 'i' || *sp == 'd')
		handle_integer(str, res, star_width, va_arg(*ap, int));
	else if (*sp == 'u')
		handle_unsigned(str, res, va_arg(*ap, unsigned int));
	else if (*sp == 'p')
		handle_pointer(str, res, va_arg(*ap, void *));
	else if (*sp == 'x')
		handle_lowhex(str, res, va_arg(*ap, unsigned int));
	else if (*sp == 'X')
		handle_uphex(str, res, va_arg(*ap, unsigned int));
	else if (*sp == 's')
		handle_string(str, res, va_arg(*ap, char *));
	else if (*sp == 'c')
		handle_char(str, res, va_arg(*ap, int));
	return (sp - str);
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
			covered = handle_specifier(&format[i], res, ap);
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
