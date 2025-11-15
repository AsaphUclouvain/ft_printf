/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:57:03 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 01:46:04 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int	bytes_read;
	char 			*result;

	result = ft_calloc(1, 1);
	va_start(ap, format);
	bytes_read = string_builder(format, &result, &ap);
	va_end(ap);
	if (bytes_read < 0)
	{
		free(result);
		return (-1);
	}
	ft_putstr(result);
	bytes_read = ft_strlen(result);
	free(result);
	return (bytes_read);
}
/*
int main(void)
{
	int ft_result;
	int result;
	//printf("hello %s\n", (char *)0);
	result =  printf("hello %20c\n", 0);
	ft_result = ft_printf("hello %20c\n", 0);
}*/
