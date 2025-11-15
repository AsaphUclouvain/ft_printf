/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:57:03 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 17:16:47 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			bytes_read;
	char		*result;

	result = ft_calloc(1, 1);
	va_start(ap, format);
	bytes_read = string_builder(format, &result, &ap);
	va_end(ap);
	if (bytes_read < 0)
	{
		free(result);
		return (-1);
	}
	ft_putstr_fd(result, 1);
	bytes_read = ft_strlen(result);
	free(result);
	return (bytes_read);
}
