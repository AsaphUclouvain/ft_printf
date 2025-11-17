/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:59:55 by anzongan          #+#    #+#             */
/*   Updated: 2025/10/23 23:44:10 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_cpy;
	const unsigned char	*s2_cpy;

	s1_cpy = (const unsigned char *)s1;
	s2_cpy = (const unsigned char *)s2;
	i = 0;
	while (i < n && *s1_cpy && *s2_cpy && *s1_cpy == *s2_cpy)
	{
		s1_cpy++;
		s2_cpy++;
		i++;
	}
	if (i == n)
		return (0);
	return (*s1_cpy - *s2_cpy);
}
