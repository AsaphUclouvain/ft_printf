/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:52:13 by anzongan          #+#    #+#             */
/*   Updated: 2025/10/26 15:01:20 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
