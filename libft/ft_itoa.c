/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:46:23 by omillan           #+#    #+#             */
/*   Updated: 2021/01/11 16:33:38 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long		size_n(long long a)
{
	long long		size;
	long long		b;

	b = a;
	size = 1;
	if (a < 0)
		size++;
	while ((b /= 10) != 0)
		size++;
	return (size);
}

static long long		sign_n(long long a)
{
	if (a < 0)
		return (-1);
	return (1);
}

char					*ft_itoa(long long a)
{
	long long		size;
	long long		sign;
	long long		b;
	char			*str;
	long long		j;

	j = 0;
	size = size_n(a);
	sign = sign_n(a);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	if (a < 0)
	{
		str[0] = '-';
		j = 1;
	}
	b = a;
	while (--size >= j)
	{
		str[size] = (b % 10) * sign + '0';
		b /= 10;
	}
	return (str);
}
