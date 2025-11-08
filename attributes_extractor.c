/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes_extractor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:40:20 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/08 00:05:39 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width(const char *str)
{
	int		i;
	int		len;
	int		val;
	char	*num;

	i = 0;
	while (str[i] && ft_strchr("0#+- ", str[i]))
		i++;
	len = 0;
	while (str[i + len] && ft_isdigit(str[i + len]))
		len++;
	if (len == 0)
		return (0);
	num = ft_substr(str, i, len);
	val = ft_atoi(num);
	free(num);
	return (val);
}

int	left_align(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr("0#+ ", str[i]))
		i++;
	return (str[i] == '-');
}

int	precision(const char *str)
{
	int		i;
	int		len;
	int		val;
	char	*num;

	i = 0;
	while (str[i] && ft_strchr("0#+- 123456789", str[i]))
		i++;
	if (str[i++] != '.')
		return (-1);
	len = 0;
	while (str[i + len] && ft_isdigit(str[i + len]))
		len++;
	if (len == 0)
		return (0);
	num = ft_substr(str, i, len);
	val = ft_atoi(num);
	free(num);
	return (val);
}

int	hashtag(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr("0+- ", str[i]))
		i++;
	return (str[i] == '#');
}

int	sign(const char *str)
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
