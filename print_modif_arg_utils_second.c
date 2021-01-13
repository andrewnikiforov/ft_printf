/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_modif_arg_utils_second.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:28:45 by omillan           #+#    #+#             */
/*   Updated: 2020/12/30 15:17:41 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			spec_is_null(int len_spec, t_parser *p)
{
	if (p->accuracy == 0)
		return (ft_put_char_ret(" ", p->width));
	else if (p->flag_itog == '0' && p->accuracy < 0)
		ft_put_char("0", p->width - len_spec);
	else
		ft_put_char(" ", p->width - 1);
	write(1, p->specifier, len_spec);
	return (p->width);
}

int			acc_is_less(int len_spec, t_parser *p)
{
	if (p->point != '.')
	{
		if (p->flag_itog == ' ')
			ft_put_char(" ", p->width - len_spec);
		if (p->flag_itog == '0')
			ft_put_char("0", p->width - len_spec);
		write(1, p->specifier, len_spec);
		return (p->width);
	}
	else if (*p->specifier == '0' && *(p->specifier + 1) == 0)
		return (spec_is_null(len_spec, p));
	else if (p->flag_itog == '0')
	{
		if (p->accuracy < 0)
			ft_put_char("0", p->width - len_spec);
		else
			ft_put_char(" ", p->width - len_spec);
		write(1, p->specifier, len_spec);
		return (p->width);
	}
	else
		ft_put_char(" ", p->width - len_spec);
	write(1, p->specifier, len_spec);
	return (p->width);
}

int			width_more_len(int len_spec, t_parser *p, int i, int j)
{
	if (p->point != '.')
	{
		write(1, "-", 1);
		ft_put_char("0", p->width - len_spec);
	}
	else
	{
		ft_put_char(" ", p->width - j);
		write(1, "-", 1);
	}
	write(1, (p->specifier + 1), len_spec - 1);
	return (i);
}

int			flag_zero(int len_spec, t_parser *p, int i, int j)
{
	if (p->accuracy == 0 && p->width > len_spec)
		return (width_more_len(len_spec, p, i, j));
	if ((p->width < len_spec && p->accuracy > len_spec) ||
												(p->accuracy == 0))
	{
		write(1, "-", 1);
		ft_put_char("0", p->accuracy - (len_spec - 1));
		write(1, (p->specifier + 1), len_spec - 1);
		return (p->accuracy + 1);
	}
	if (p->accuracy < 0)
	{
		write(1, "-", 1);
		ft_put_char("0", p->width - len_spec);
	}
	else
	{
		ft_put_char(" ", p->width - j);
		write(1, "-", 1);
		ft_put_char("0", j - len_spec);
	}
	write(1, (p->specifier + 1), len_spec - 1);
	return (j > i) ? (j) : (i);
}

int			flag_minus(int len_spec, t_parser *p, int i, int j)
{
	write(1, "-", 1);
	ft_put_char("0", p->accuracy - (len_spec - 1));
	write(1, (p->specifier + 1), len_spec - 1);
	if (p->accuracy + 1 < p->width)
		ft_put_char(" ", p->width - j);
	return (j > i) ? (j) : (i);
}
