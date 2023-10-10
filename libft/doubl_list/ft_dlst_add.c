/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:53:17 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/22 17:00:01 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_dlst_addnode(t_dlist **list, t_node *node, size_t position)
{
	size_t	index;
	t_dlist	**list_tmp;

	index = 2;
	list_tmp = list;
	if (!list || !node || position < 2 || position > (*list)->len)
		return ;
	while (index != position)
	{
		(*list_tmp)->head = (*list_tmp)->head->next;
		index++;
	}
	node->next = (*list_tmp)->head->next;
	(*list_tmp)->head->next->prev = node;
	(*list_tmp)->head->next = node;
	node->prev = (*list_tmp)->head;
}
