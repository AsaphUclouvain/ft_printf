/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:57:38 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 22:45:00 by anzongan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_segment
{
	int		*b_rd;
	char	*sp;
}	t_segment;

typedef struct s_width_precision
{
	int	width;
	int	precision;
}	t_width_precision;

typedef struct s_attributes
{
	int	width;
	int	precision;
	int	left_align;
	int	zero_padding;
	int	hashtag;
	int	plus;
	int	space;
}	t_attributes;

t_width_precision	*wp_builder(const char *str, va_list *ap);
t_attributes		*set_attributes(const char *str, t_width_precision *wp);
long				ft_abs(int val);
void				write_spaces(int width);
void				generic_converter(int negative, char type, char **str_num,\
	t_attributes *atr);
void				handle_char(int *bytes_read,\
	int c, t_attributes *atr);
void				handle_lowhex(int *bytes_read,\
	unsigned int value, t_attributes *atr);
void				handle_uphex(int *bytes_read,\
	unsigned int value, t_attributes *atr);
void				handle_percent(int *bytes_read);
void				handle_integer(int *bytes_read,\
	int value, t_attributes *atr);
void				handle_pointer(int *bytes_read,\
	unsigned long long ptr, t_attributes *atr);
void				handle_string(int *bytes_read,\
	char *new_str, t_attributes *atr);
void				handle_unsigned_int(int *bytes_read,\
	unsigned int value, t_attributes *atr);
void				apply_zero_padding(int width, char **str);
void				apply_width(int left_align, int width, char **str);
void				attributes_annulation(int negative,\
	unsigned long long value, char type, t_attributes *atr);
char				*ft_itoa_base(unsigned long long num, int base_len,\
	const char *base);
char				*first_specifier(const char *str);
int					valid_order(const char *str);
int					handle_specifier(const char *str,\
	va_list *ap, t_segment *seg);
int					handle_format(int *bytes_read, const char *str,\
	va_list *ap);
int					string_builder(int *bytes_read, const char *format,\
	va_list *ap);
int					isspecifier(char c);
int					ft_printf(const char *format, ...);
int					zero_padding(const char *str);
int					space(const char *str);
int					plus(const char *str);
int					hashtag(const char *str);
int					width(const char *str);
int					left_align(const char *str);
int					precision(const char *str);
int					ft_min(int a, int b);
int					ft_max(int a, int b);

#endif
