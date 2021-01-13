/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:25:55 by omillan           #+#    #+#             */
/*   Updated: 2020/11/01 17:28:48 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = -1;
	if (!*to_find)
		return ((char *)str);
	while (++i < len && *(str + i))
	{
		j = 0;
		if (*(str + i + j) == *(to_find + j))
		{
			k = 0;
			while (i + j < len + 1 && *(str + i + j) && *(to_find + j))
			{
				if (*(str + i + j) != *(to_find + j))
					break ;
				j++;
				k++;
			}
			if (k == ft_strlen(to_find))
				return ((char *)str + i);
		}
	}
	return (NULL);
}
