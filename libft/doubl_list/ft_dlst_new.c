/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:10:54 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/10 16:58:31 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dlist	*ft_dlst_new()
{
	t_dlist	*new_list;

	new_list = malloc(sizeof(t_dlist));
	if (!new_list)
		return (NULL);
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->len = 0;
	return (new_list);
}
