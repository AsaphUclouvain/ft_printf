/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:57:03 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/17 06:49:10 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			bytes_read;
	int			exit_status;

	bytes_read = 0;
	va_start(ap, format);
	exit_status = string_builder(&bytes_read, format, &ap);
	va_end(ap);
	if (exit_status < 0)
		return (-1);
	return (bytes_read);
}
