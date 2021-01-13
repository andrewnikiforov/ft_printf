/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:15:50 by omillan           #+#    #+#             */
/*   Updated: 2020/11/01 16:10:10 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *p;
	unsigned char *a;
	unsigned char k;

	p = (unsigned char *)dst;
	a = (unsigned char *)src;
	k = (unsigned char)c;
	while (n--)
	{
		if (*a == k)
		{
			*p++ = *a;
			return (p);
		}
		else
			*p++ = *a++;
	}
	return (NULL);
}
