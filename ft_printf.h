/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:40:37 by omillan           #+#    #+#             */
/*   Updated: 2020/12/30 15:25:37 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_parser
{
	int				len;
	int				width;
	int				accuracy;
	char			*specifier;
	char			c;
	char			flag_itog;
	int				str_chr;
	char			point;
	int				x;
	int				c_nul;
	int				p_if;
}					t_parser;

int					ft_printf(const char *format, ...);
t_parser			*func_parser(const char *s, va_list l);
char				*ft_itoa_base(long long a, int i, int base);
int					print_s_c_per(t_parser *p);
int					print_d(t_parser *p);
int					print_s_c_per(t_parser *p);
void				ft_put_char(char *c, int i);
char				*ft_itoa_base_p(unsigned long long a, int i, int base,
															t_parser *p);
int					for_helper(int len_spec, t_parser *p);
int					ft_put_char_ret(char *c, int i);
int					print_if_point(t_parser *p);
int					len_spec_max(int len_spec, t_parser *p);
int					acc_mor_width(int len_spec, t_parser *p);
void				acc_less(int len_spec, t_parser *p);
int					spec_is_null(int len_spec, t_parser *p);
int					acc_is_less(int len_spec, t_parser *p);
int					width_more_len(int len_spec, t_parser *p, int i, int j);
int					flag_zero(int len_spec, t_parser *p, int i, int j);
int					flag_minus(int len_spec, t_parser *p, int i, int j);

#endif
