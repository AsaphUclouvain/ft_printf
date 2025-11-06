/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:09:14 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/06 23:25:58 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	extract_width(const char *str)
{
	int		i;
	int		len;
	int		val;
	char	*num;

	i = 0;
	while (str[i] && ft_strchr("0#+- ", str[i]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		i++;
		len++;
	}
	num = (char *)malloc(len + 1);
	i -= len;
	while (str[i] && ft_isdigit(str[i]))
	{
		num[i - len] = str[i];
		i++;
	}
	num[len] = '\0';
	val = ft_atoi(num);
	free(num);
	return (val);
}

static int	left_aligment(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr("0#+ ", str[i]))
		i++;
	if (str[i] == '-')
		return (1);
	return (0);
}

static void	add_char(char **res, int c, int rep)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)malloc(ft_strlen(*res) + rep + 1);
	if (!tmp)
		return ;
	i = 0;
	while (*res[i])
	{
		tmp[i] = *res[i];
		i++;
	}
	free(*res);
	j = 0;
	while (str[j] && j < rep)
	{
		tmp[i + j] = c;
		j++;
	}
	tmp[i + j] = '\0';
	res = tmp;
}

void	handle_char(char *str, char **res, int c, t_width_precision* wp)
{
	int	w;
	char	*tmp;

	w = extract_width(str);
	if (wp && wp->width)
		w = wp->width;
	free(wp);
	if (w <= 1)
		add_char(res, c, 1);
	else
	{
		if (left_alignment(str))
		{
			add_char(res, c, 1);
			add_char(res, 32, w - 1);
		}
		else
		{
			add_char(res, 32, w - 1);
			add_char(res, c, 1);
		}		
	}
}
