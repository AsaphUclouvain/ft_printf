/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes_extractor2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:59:04 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/11 15:01:22 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hashtag(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr("0+- ", str[i]))
		i++;
	return (str[i] == '#');
}

int	plus(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr("0#- ", str[i]))
		i++;
	return (str[i] == '+');
}

int	space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr("0#+-", str[i]))
		i++;
	return (str[i] == ' ');
}

int	zero_padding(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr("#+- ", str[i]))
		i++;
	return (str[i] == '0');
}

