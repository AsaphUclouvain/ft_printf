/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:22:00 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/14 04:00:53 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_char(int rep, int c, char **res)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)malloc(ft_strlen(*res) + rep + 1);
	if (!tmp)
		return ;
	i = 0;
	while ((*res)[i])
	{
		tmp[i] = (*res)[i];
		i++;
	}
	j = 0;
	while (j < rep)
	{
		tmp[i + j] = c;
		j++;
	}
	tmp[i + j] = '\0';
	free(*res);
	*res = tmp;
}

void	add_str(char *new_str, char **res)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)malloc(ft_strlen(*res) + ft_strlen(new_str) + 1);
	if (!tmp)
		return ;
	i = 0;
	while ((*res)[i])
	{
		tmp[i] = (*res)[i];
		i++;
	}
	j = 0;
	while (new_str[j])
	{
		tmp[i + j] = new_str[j];
		j++;
	}
	tmp[i + j] = '\0';
	free(*res);
	*res = tmp;
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_cpy;

	i = 0;
	s_cpy = (unsigned char *)s;
	while (i < n)
	{
		s_cpy[i] = '\0';
		i++;
	}
}
