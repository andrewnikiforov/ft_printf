/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_modif_arg_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 11:09:45 by omillan           #+#    #+#             */
/*   Updated: 2021/01/11 16:42:00 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_put_char(char *c, int i)
{
	if (i < 1)
		return ;
	while (i--)
		write(1, c, 1);
}

int					ft_put_char_ret(char *c, int i)
{
	int j;

	j = i;
	while (i--)
		write(1, c, 1);
	return (j);
}

int					print_if_point(t_parser *p)
{
	if (p->width == 0 && p->accuracy >= 0)
	{
		write(1, "0x", 2);
		return (ft_put_char_ret("0", p->accuracy) + 2);
	}
	if (p->flag_itog == '-')
	{
		write(1, "0x", 2);
		return (ft_put_char_ret(" ", p->width - 2) + 2);
	}
	ft_put_char(" ", p->width - 2);
	write(1, "0x", 2);
	return (p->width);
}

int					len_spec_max(int len_spec, t_parser *p)
{
	if (p->point == '.' && *p->specifier == '0' && p->accuracy == 0)
	{
		if (*p->specifier == '0' && *(p->specifier + 1) == 0)
			return (ft_put_char_ret(" ", p->width));
	}
	else if (p->point == '.' && *p->specifier == '0' && p->accuracy == 1)
		return (ft_put_char_ret("0", 1));
	return (write(1, p->specifier, len_spec));
}

int					acc_mor_width(int len_spec, t_parser *p)
{
	if (ft_strchr(p->specifier, 'x'))
	{
		write(1, "0x", 2);
		p->specifier += 2;
		p->x = 2;
	}
	ft_put_char("0", p->accuracy - (len_spec - p->x));
	write(1, p->specifier, len_spec - p->x);
	p->specifier -= p->x;
	return (p->accuracy + p->x);
}
