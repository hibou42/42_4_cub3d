/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:10:30 by nrossel           #+#    #+#             */
/*   Updated: 2023/08/23 22:02:49 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

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
