/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:38:14 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/04 23:41:08 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_parser(const char *str, char **width)
{
	int		i;
	char	*s;

	i = 0;
	if (str[i] == "*")
		return ((char *)str);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	s = (char *)malloc(i + 1);
	if (!s)
		return ((char *)str);
	i = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	*width = s;
	return ((char *)str + i);
}
