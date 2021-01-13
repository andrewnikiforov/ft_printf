/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_modif_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 19:05:14 by omillan           #+#    #+#             */
/*   Updated: 2020/12/30 15:33:42 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					helper(int len_spec, t_parser *p)
{
	if (p->flag_itog == ' ')
		ft_put_char(" ", p->width - len_spec);
	if (p->flag_itog == '0')
		ft_put_char("0", p->width - len_spec);
	if (p->flag_itog == '-')
		write(1, p->specifier, len_spec);
	ft_put_char(" ", p->width - len_spec);
	return (p->width);
}

static int			if_flag_minus(int len_spec, t_parser *p)
{
	if (p->width >= p->accuracy && len_spec >= p->accuracy)
	{
		if (p->point != '.')
			return (helper(len_spec, p));
		if (*p->specifier == '0')
		{
			if (p->accuracy == 0)
				ft_put_char(" ", p->width);
			else
			{
				write(1, "0", 1);
				ft_put_char(" ", p->width - 1);
			}
			return (p->width);
		}
		write(1, p->specifier, len_spec);
		ft_put_char(" ", p->width - len_spec);
		return (p->width);
	}
	ft_put_char("0", p->accuracy - len_spec);
	write(1, p->specifier, len_spec);
	ft_put_char(" ", p->width - p->accuracy);
	return (p->width);
}

static int			print_digit_without_minus(int len_spec, t_parser *p)
{
	if (len_spec >= p->width && len_spec >= p->accuracy)
		return (len_spec_max(len_spec, p));
	else if (p->accuracy >= p->width)
		return (acc_mor_width(len_spec, p));
	else if (p->flag_itog == '-')
		return (if_flag_minus(len_spec, p));
	else if (p->width >= p->accuracy && len_spec >= p->accuracy)
		return (acc_is_less(len_spec, p));
	ft_put_char(" ", p->width - p->accuracy);
	ft_put_char("0", p->accuracy - len_spec);
	write(1, p->specifier, len_spec);
	return (p->width);
}

static int			print_digit_with_minus(int len_spec, t_parser *p)
{
	int i;
	int j;

	j = 0;
	i = 0;
	i = (p->accuracy + 1 > p->width) ? (p->accuracy + 1) : (p->width);
	j = (p->accuracy + 1 > len_spec) ? (p->accuracy + 1) : (len_spec);
	if (len_spec >= p->width && len_spec > p->accuracy)
	{
		ft_put_char(" ", p->width - len_spec);
		return (write(1, p->specifier, len_spec));
	}
	else if (p->flag_itog == '-')
		return (flag_minus(len_spec, p, i, j));
	else if (p->flag_itog == '0')
		return (flag_zero(len_spec, p, i, j));
	ft_put_char(" ", p->width - j);
	write(1, "-", 1);
	ft_put_char("0", p->accuracy - (len_spec - 1));
	write(1, (p->specifier + 1), len_spec - 1);
	return (i);
}

int					print_d(t_parser *p)
{
	char	minus;
	int		len_spec;

	if (ft_strncmp(p->specifier, "0x0", 3) == 0 && p->point == '.')
	{
		if (p->width == 0 && p->accuracy == 0 && p->point == '.')
			return (write(1, "0x", 2));
		if (p->width == 0 && p->accuracy <= 0 && p->point == '.')
			return (write(1, "0x0", 3));
		return (print_if_point(p));
	}
	minus = '0';
	if (*p->specifier == '-' && ft_isdigit(*(p->specifier + 1)))
		minus = '-';
	len_spec = ft_strlen(p->specifier);
	return (minus == '-') ? print_digit_with_minus(len_spec, p) :
	print_digit_without_minus(len_spec, p);
}
