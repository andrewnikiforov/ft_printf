/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:35:59 by omillan           #+#    #+#             */
/*   Updated: 2020/12/20 18:24:37 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	len = 0;
	if (!s1 || !s2)
		return (NULL);
	if (s1)
		len = ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	i = -1;
	j = -1;
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (++i < (len + 1) && *(s1 + i))
		*(str + i) = *(s1 + i);
	while (i + ++j < len && *(s2 + j))
		*(str + i + j) = *(s2 + j);
	*(str + i + j) = '\0';
	free(s2);
	return (str);
}
