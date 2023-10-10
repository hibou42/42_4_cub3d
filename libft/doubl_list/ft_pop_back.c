/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:24:18 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/22 15:00:21 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_node	*ft_pop_back(t_dlist **lst)
{
	t_node	*node;

	if (!lst || !(*lst)->head)
		return (0);
	node = (*lst)->tail;
	(*lst)->tail = (*lst)->tail->prev;
	(*lst)->tail->next = NULL;
	(*lst)->len--;
	return (node);
}
