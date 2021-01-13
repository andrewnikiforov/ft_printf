/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:43:13 by omillan           #+#    #+#             */
/*   Updated: 2020/11/07 16:46:21 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *data)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	node->content = data;
	node->next = NULL;
	return (node);
}
