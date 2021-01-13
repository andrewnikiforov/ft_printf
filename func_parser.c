/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:53:23 by omillan           #+#    #+#             */
/*   Updated: 2021/01/11 16:38:54 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_parser			*make_parser(void)
{
	t_parser	*p;

	if (!(p = (t_parser *)malloc(sizeof(t_parser))))
		return (0);
	p->len = 1;
	p->width = 0;
	p->accuracy = 0;
	p->specifier = NULL;
	p->c = 0;
	p->flag_itog = 0;
	p->width = 0;
	p->str_chr = 0;
	p->point = 1;
	p->x = 0;
	p->c_nul = 0;
	p->p_if = 0;
	return (p);
}

static char				itog_flag(t_parser *p, const char **s)
{
	char	c;
	int		flag_minus;
	int		flag_zero;

	flag_minus = 0;
	flag_zero = 0;
	*s += 1;
	while (**s == '-' || **s == '0')
	{
		if (**s == '-')
			flag_minus++;
		if (**s == '0')
			flag_zero++;
		p->len += 1;
		*s += 1;
	}
	c = (flag_zero > 0) ? ('0') : (' ');
	c = (flag_minus > 0) ? ('-') : ('0');
	if (flag_minus == 0 && flag_zero == 0)
		c = ' ';
	return (c);
}

static void				specifier_or_c(char s, t_parser *p, va_list l)
{
	p->str_chr = (s == 's' || s == 'c' || s == '%') ? (1) : (0);
	if (s == 's')
		p->specifier = ft_strdup(va_arg(l, char *));
	else if (s == 'c')
	{
		p->c = va_arg(l, int);
		if (p->c == '\0')
			p->c_nul = 1;
	}
	else if (s == 'd' || s == 'i')
		p->specifier = ft_itoa_base(va_arg(l, int), 1, 10);
	else if (s == 'p')
		p->specifier = ft_strjoin("0x",
					ft_itoa_base_p(va_arg(l, unsigned long long), 0, 16, p));
	else if (s == 'x')
		p->specifier = ft_itoa_base(va_arg(l, unsigned int), 0, 16);
	else if (s == 'X')
		p->specifier = ft_itoa_base(va_arg(l, unsigned int), 1, 16);
	else if (s == 'u')
		p->specifier = ft_itoa_base(va_arg(l, unsigned int), 1, 10);
	else if (s == '%')
		p->c = '%';
	else
		p->specifier = ft_strdup("_");
	p->len++;
}

static void				star_or_not(t_parser *p, int *width_or_accuracy,
												const char **s, va_list l)
{
	if (**s == '*')
	{
		*width_or_accuracy = va_arg(l, int);
		p->len += 1;
		*s += 1;
	}
	else
	{
		while (ft_isdigit(**s))
		{
			*width_or_accuracy = *width_or_accuracy * 10 + (**s - '0');
			p->len += 1;
			*s += 1;
		}
	}
}

t_parser				*func_parser(const char *s, va_list l)
{
	t_parser	*p;

	p = make_parser();
	p->flag_itog = itog_flag(p, &s);
	star_or_not(p, &p->width, &s, l);
	if (*s == '.')
	{
		p->point = '.';
		p->len += 1;
		s++;
	}
	star_or_not(p, &p->accuracy, &s, l);
	if (p->width < 0)
	{
		p->flag_itog = '-';
		p->width *= -1;
	}
	specifier_or_c(*s, p, l);
	return (p);
}
