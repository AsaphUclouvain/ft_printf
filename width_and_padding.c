/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:45:40 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/11 14:48:01 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_zero_padding(int width, char **str)
{
	int		i;
	int		j;
	int		len_after_prefix;
	char	*new_str;

	new_str = (char *)malloc(width + 1);
	if (!new_str)
		return ;
	i = 0;
	while ((*str)[i] && ft_strchr("0xX +-", (*str)[i]))
	{
		new_str[i] = (*str)[i];
		i++;
	}
	len_after_prefix = ft_strlen(*str) - i;
	j = i;
	while (i < width - len_after_prefix)
		new_str[i++] = '0';
	while ((*str)[j])
		new_str[i++] = (*str)[j++];
	new_str[i] = '\0';
	free(*str);
	*str = new_str;
}

static void	add_space_after(int width, char **str)
{
	int		i;
	char	*new_str;

	new_str = (char *)malloc(width + 1);
	if (!new_str)
		return ;
	i = 0;
	while ((*str)[i])
	{
		new_str[i] = (*str)[i];
		i++;
	}
	while (i < width)
		new_str[i++] = ' ';
	new_str[i] = '\0';
	free(*str);
	*str = new_str;
}

static void	add_space_before(int width, char **str)
{
	int		i;
	int		j;
	char	*new_str;

	new_str = (char *)malloc(width + 1);
	if (!new_str)
		return ;
	i = 0;
	while (i < width - ft_strlen(*str))
		new_str[i++] = ' ';
	j = 0;
	while ((*str)[j])
	{
		new_str[i + j] = (*str)[j];
		j++;
	}
	new_str[i + j] = '\0';
	free(*str);
	*str = new_str;
}

void	apply_width(int left_align, int width, char **str)
{
	if (left_align)
		add_space_after(width, str);
	else
		add_space_before(width, str);
}

