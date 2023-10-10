/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:24:18 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/10 16:55:40 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
