/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:42:39 by omillan           #+#    #+#             */
/*   Updated: 2020/11/07 16:45:46 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		del(tmp->content);
		*lst = tmp->next;
		free(tmp);
	}
	*lst = NULL;
}
