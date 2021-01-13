/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:02:37 by omillan           #+#    #+#             */
/*   Updated: 2020/11/09 19:49:00 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (n-- > 0)
		*a++ = *b++;
	return (dst);
}
