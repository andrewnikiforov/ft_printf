/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:43:19 by omillan           #+#    #+#             */
/*   Updated: 2020/11/07 16:43:21 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = lst;
	if (!tmp)
		return (size);
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
