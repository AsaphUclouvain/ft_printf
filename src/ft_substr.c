/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:32:54 by anzongan          #+#    #+#             */
/*   Updated: 2025/10/26 18:04:15 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	len_s;
	char			*res;

	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_calloc(1, 1));
	res = (char *)malloc(ft_min(len, len_s - start) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && start + i < len_s)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
