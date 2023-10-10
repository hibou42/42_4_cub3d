/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_addback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:05:14 by nrossel           #+#    #+#             */
/*   Updated: 2023/08/23 13:15:39 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_dlst_addback(t_dlist **lst, t_node *new)
{
	if (!new || !lst)
		return ;
	if ((*lst)->head == NULL)
		(*lst)->head = new;
	else
	{
		(*lst)->tail->next = new;
		new->prev = (*lst)->tail;
	}
	(*lst)->tail = new;
	(*lst)->len++;
}
