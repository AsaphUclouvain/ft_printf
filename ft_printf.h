/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:57:38 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/06 23:39:47 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

typedef	struct s_width_precision {
	int	width;
	int	precision;
}	t_width_precision;

typedef struct s_attributes {
	int	width;
	int	precision;
	int	left_align;
	int	zero_padding;
	int	hashtag;
	int	sign;
	int	space;
}	t_attributes;

#endif
