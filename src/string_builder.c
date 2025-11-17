/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:15:30 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/16 00:05:56 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	handle_specifier(const char *str, va_list *ap, t_segment *seg)
{
	t_attributes	*atr;

	atr = set_attributes(str, wp_builder(str, ap));
	if (!atr)
		return (-1);
	else if (*(seg->sp) == '%')
		handle_percent(seg->b_rd);
	else if (*(seg->sp) == 'i' || *(seg->sp) == 'd')
		handle_integer(seg->b_rd, va_arg(*ap, int), atr);
	else if (*(seg->sp) == 'u')
		handle_unsigned_int(seg->b_rd, va_arg(*ap, unsigned int), atr);
	else if (*(seg->sp) == 'x')
		handle_lowhex(seg->b_rd, va_arg(*ap, unsigned int), atr);
	else if (*(seg->sp) == 'X')
		handle_uphex(seg->b_rd, va_arg(*ap, unsigned int), atr);
	else if (*(seg->sp) == 'p')
		handle_pointer(seg->b_rd, \
(unsigned long long)va_arg(*ap, void *), atr);
	else if (*(seg->sp) == 'c')
		handle_char(seg->b_rd, va_arg(*ap, int), atr);
	else if (*(seg->sp) == 's')
		handle_string(seg->b_rd, va_arg(*ap, char *), atr);
	free(atr);
	return (seg->sp - str + 2);
}

int	handle_format(int *bytes_read, const char *str, va_list *ap)
{
	t_segment	*seg;
	int			char_count;
	int			order;

	if (!str || !ap)
		return (-1);
	order = valid_order(str);
	if (order == -1)
		return (-1);
	if (order == -2)
	{
		*bytes_read += write(1, "%", 1);
		return (1);
	}
	seg = (t_segment *)malloc(sizeof(t_segment));
	if (!seg)
		return (-1);
	seg->b_rd = bytes_read;
	seg->sp = first_specifier(str);
	if (!seg->sp)
		return (1);
	char_count = handle_specifier(str, ap, seg);
	free(seg);
	return (char_count);
}

int	string_builder(int *bytes_read, const char *format, va_list *ap)
{
	int	i;
	int	covered;

	i = 0;
	while (format[i])
	{
		covered = 0;
		if (format[i] == '%')
			covered = handle_format(bytes_read, format + i + 1, ap);
		else
		{
			while (format[i + covered] && format[i + covered] != '%')
				covered++;
			*bytes_read += write(1, format + i, covered);
		}
		if (covered < 0)
			return (-1);
		i += covered;
	}
	return (i);
}
