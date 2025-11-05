/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:25:33 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/04 22:57:11 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*flag_parser(const char *str, char **flags)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] && ft_strchr("0#+- ", str[i]))
		i++;
	s = (char *)malloc(i + 1);
	if (!s)
		return ((char *)str);
	i = 0;
	while (str[i] && ft_strchr("0#+- ", str[i]))
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	*flags = s;
	return ((char *)str + i);
}
