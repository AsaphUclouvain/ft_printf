/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzongan <anzongan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:57:38 by anzongan          #+#    #+#             */
/*   Updated: 2025/11/15 17:28:46 by anzongan         ###   ########.fr       */
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
void				generic_converter(int negative, char type, char **str_num, \
	t_attributes *atr);
void				handle_char(char **res, int c, t_attributes *atr);
void				handle_lowhex(char **res, unsigned int value, \
	t_attributes *atr);
void				handle_uphex(char **res, unsigned int value, \
	t_attributes *atr);
void				handle_percent(char **res);
void				handle_integer(char **res, int value, \
	t_attributes *atr);
void				handle_pointer(char **res, unsigned long ptr, \
	t_attributes *atr);
void				handle_string(char **res, char *new_str, \
	t_attributes *atr);
void				handle_unsigned_int(char **res, unsigned int value, \
	t_attributes *atr);
void				apply_zero_padding(int width, char **str);
void				apply_width(int left_align, int width, char **str);
void				add_str(char *new_str, char **res);
void				add_char(int rep, int c, char **res);
void				attributes_annulation(int negative, \
	unsigned long long value, char type, t_attributes *atr);
char				*ft_itoa_base(unsigned long long num, int base_len, \
	const char *base);
char				*first_specifier(const char *str);
int					valid_order(const char *str);
int					valid_chars(const char *str);
int					handle_specifier(const char *str, char *sp, char **res, \
	va_list *ap);
int					handle_format(const char *str, char **res, va_list *ap);
int					string_builder(const char *format, char **res, va_list *ap);
int					char_sequence(int len, const char *str, \
	char **res);
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
