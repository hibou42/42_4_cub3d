/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:51:02 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/10 16:58:09 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlst_delone(t_node *lst, void (*del)(void *))
{
	(void)del;
	if (!lst)
		return ;
	lst->next = NULL;
	lst->prev = NULL;
	free(lst);
	lst = NULL;
}
