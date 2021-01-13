/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:48:54 by omillan           #+#    #+#             */
/*   Updated: 2020/11/08 18:09:02 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p;
	unsigned char a;

	p = (unsigned char *)s;
	a = (unsigned char)c;
	while (n--)
	{
		if (*p == a)
			return (p);
		p++;
	}
	return (NULL);
}
