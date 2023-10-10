/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_addfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:13:01 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/22 16:45:53 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_dlst_addfront(t_dlist **lst, t_node *new)
{
	if (!new || !lst)
		return ;
	if ((*lst)->len == 0)
		(*lst)->tail = new;
	else
	{
		(*lst)->head->prev = new;
		new->next = (*lst)->head;
	}
	(*lst)->head = new;
	(*lst)->len++;
}
