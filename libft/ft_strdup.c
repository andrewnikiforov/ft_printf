/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:34:03 by omillan           #+#    #+#             */
/*   Updated: 2020/12/20 20:17:53 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*rez;
	size_t	i;
	size_t	j;

	j = -1;
	if (!s1)
		return (0);
	i = ft_strlen(s1);
	if (!(rez = malloc(i + 1)))
		return (NULL);
	while (++j < i)
		rez[j] = s1[j];
	rez[j] = '\0';
	return (rez);
}
