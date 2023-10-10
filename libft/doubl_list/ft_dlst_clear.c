/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:10:30 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/10 16:55:40 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlst_clear(t_dlist **dlst, void (*del)(void *))
{
	t_node	*ptr;

	if (!*dlst)
		return ;
	ptr = (*dlst)->head;
	while ((*dlst)->head != NULL)
	{
		ptr = (*dlst)->head->next;
		ft_dlst_delone((*dlst)->head, del);
		(*dlst)->head = ptr;
	}
	(*dlst)->head = NULL;
	(*dlst)->tail = NULL;
	*dlst = NULL;
	free(*dlst);
	dlst = NULL;
	free(dlst);
}
