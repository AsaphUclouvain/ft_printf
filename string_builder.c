/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:15:30 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/01 16:56:57 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int	string_builder(const char *format, char **res, va_list ap)
{
	int	i;
	char	*subchar;

	i = 0;
	while (format[i] && format[i] != '%')
	{
		if (format[i] == '%')
			//call a general handle
		len = 0;
		while (format[i] && format[i] != '%')
			len++;
		subchar = ft_substr(format + i);;
		*res = ft_strjoin();
		i++;
	}
}
