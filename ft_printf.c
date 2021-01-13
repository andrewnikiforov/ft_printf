/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:54:42 by omillan           #+#    #+#             */
/*   Updated: 2021/01/11 17:04:14 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_free(t_parser *p, va_list l)
{
	if (!p || !l)
		return ;
	if (p->specifier)
		free(p->specifier);
	if (p)
		free(p);
	va_end(l);
}

static int		ft_wrong(t_parser *p, va_list l)
{
	if (p->specifier && *p->specifier == '_')
	{
		ft_free(p, l);
		write(1, "0x0", 3);
		return (-1);
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	int				length;
	t_parser		*p;
	va_list			l;

	p = 0;
	va_start(l, format);
	length = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format++, 1);
			length++;
		}
		else
		{
			p = func_parser(format, l);
			if (ft_wrong(p, l) == -1)
				return (-1);
			length += (p->str_chr > 0) ? (print_s_c_per(p)) : (print_d(p));
			format += p->len;
		}
	}
	ft_free(p, l);
	return (length);
}
