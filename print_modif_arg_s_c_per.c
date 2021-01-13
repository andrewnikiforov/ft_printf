/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_modif_arg_s_c_per.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:44:27 by omillan           #+#    #+#             */
/*   Updated: 2020/12/30 15:15:11 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_strlenn(const char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int			print_c_per(t_parser *p)
{
	if (p->flag_itog == '-')
	{
		write(1, &p->c, 1);
		ft_put_char(" ", p->width - 1);
		return (p->width > 0) ? (p->width) : (1);
	}
	else if (p->flag_itog == '0' && p->c == '%')
	{
		ft_put_char("0", p->width - 1);
		write(1, &p->c, 1);
		return (p->width > 0) ? (p->width) : (1);
	}
	ft_put_char(" ", p->width - 1);
	write(1, &p->c, 1);
	return (p->width > 0) ? (p->width) : (1);
}

static int			print_if_no_point(t_parser *p)
{
	if (p->width <= ft_strlenn(p->specifier))
		return (write(1, p->specifier, ft_strlen(p->specifier)));
	if (p->flag_itog == '-')
	{
		write(1, p->specifier, ft_strlen(p->specifier));
		ft_put_char(" ", p->width - ft_strlen(p->specifier));
		return (p->width);
	}
	if (p->flag_itog == '0')
	{
		ft_put_char("0", p->width - ft_strlen(p->specifier));
		write(1, p->specifier, ft_strlen(p->specifier));
		return (p->width);
	}
	ft_put_char(" ", p->width - ft_strlen(p->specifier));
	write(1, p->specifier, ft_strlen(p->specifier));
	return (p->width);
}

static int			help(t_parser *p)
{
	int	i;
	int j;

	if (p->accuracy >= ft_strlenn(p->specifier))
	{
		ft_put_char(" ", p->width - ft_strlenn(p->specifier));
		write(1, p->specifier, ft_strlenn(p->specifier));
		return (p->width);
	}
	i = (p->accuracy > ft_strlenn(p->specifier)) ? (ft_strlenn(p->specifier)) :
																(p->accuracy);
	j = (p->width > p->accuracy) ? (p->accuracy) : (p->width);
	ft_put_char(" ", p->width - p->accuracy);
	if (ft_strlenn(p->specifier) == 0)
	{
		ft_put_char(" ", j);
		return (j);
	}
	else
		ft_put_char(" ", p->accuracy - ft_strlenn(p->specifier));
	write(1, p->specifier, i);
	return (p->accuracy > p->width) ? (p->accuracy) : (p->width);
}

int					print_s_c_per(t_parser *p)
{
	int	i;

	if (p->c_nul == 1 || p->c != 0)
		return (print_c_per(p));
	if (p->specifier == 0)
		p->specifier = ft_strdup("(null)");
	if (p->accuracy < 0 && p->width > 0)
		p->accuracy = ft_strlenn(p->specifier);
	i = (p->accuracy > ft_strlenn(p->specifier)) ? ft_strlenn(p->specifier)
															: p->accuracy;
	if (p->point == 1)
		return (print_if_no_point(p));
	if (p->width == 0 && p->accuracy == 0)
		return (0);
	if (p->accuracy == 0)
		return (ft_put_char_ret(" ", p->width));
	if ((p->width <= ft_strlenn(p->specifier) && p->accuracy >=
			ft_strlenn(p->specifier)) || (p->accuracy < 0 && p->width == 0))
		return (write(1, p->specifier, ft_strlenn(p->specifier)));
	if (p->flag_itog != '-')
		return (help(p));
	write(1, p->specifier, i);
	ft_put_char(" ", p->width - i);
	return (p->width >= i) ? (p->width) : (i);
}
