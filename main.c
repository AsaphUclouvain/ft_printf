/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:57:03 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/01 15:32:03 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	unsigned int	bytes_read;
	char 			*result;

	va_start(ap);
	while (*format)
	{
		bytes_read += string_builder(&result, format);
		if (bytes_read < 0)
			return (-1);
		format += bytes_read;
	}

	ft_putstr(result);
	return bytes_read;
}
