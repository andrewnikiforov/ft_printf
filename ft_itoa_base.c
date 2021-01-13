/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:57:57 by omillan           #+#    #+#             */
/*   Updated: 2021/01/11 16:42:52 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	tab_index(int index, int i)
{
	const char tab_x[17] = "0123456789abcdef";
	const char tab_y[17] = "0123456789ABCDEF";

	return (i > 0) ? (tab_y[index]) : (tab_x[index]);
}

char			*ft_itoa_base_p(unsigned long long a, int i, int base,
																t_parser *p)
{
	char					*rez;
	unsigned long long		len;
	unsigned long long		b;
	unsigned int			j;

	p->p_if = 1;
	b = (a < 0) ? (a * -1) : (a);
	j = (a < 0) ? (1) : (0);
	len = (a < 0) ? (2) : (1);
	while ((b /= base) != 0)
		len++;
	if (!(rez = malloc(len + 1)))
		return (0);
	rez[len] = '\0';
	b = (a < 0) ? (a * -1) : (a);
	if (a < 0)
		rez[0] = '-';
	while (--len >= j)
	{
		rez[len] = tab_index((b - (base * (b / base))), i);
		b /= base;
		if (len == 0)
			break ;
	}
	return (rez);
}

char			*ft_itoa_base(long long a, int i, int base)
{
	char			*rez;
	long long		len;
	long long		b;
	int				j;

	b = (a < 0) ? (a * -1) : (a);
	j = (a < 0) ? (1) : (0);
	len = (a < 0) ? (2) : (1);
	while ((b /= base) != 0)
		len++;
	if (!(rez = malloc(len + 1)))
		return (0);
	rez[len] = '\0';
	b = (a < 0) ? (a * -1) : (a);
	if (a < 0)
		rez[0] = '-';
	while (--len >= j)
	{
		rez[len] = tab_index((b - (base * (b / base))), i);
		b /= base;
		if (len == 0)
			break ;
	}
	return (rez);
}
