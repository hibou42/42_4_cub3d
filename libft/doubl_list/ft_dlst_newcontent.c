/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_newcontent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:20:14 by nrossel           #+#    #+#             */
/*   Updated: 2023/08/26 07:34:17 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_node	*ft_dlst_newcontent(void *data, t_dlist **trash_lst)
{
	t_node	*new_node;
	int		*data_mllc;

	data_mllc = NULL;
	new_node = my_malloc(1, sizeof(t_node), trash_lst);
	if (!new_node)
		return (0);
	if (data)
	{
		data_mllc = my_malloc(1, sizeof(void), trash_lst);
		if (!data_mllc)
			return (0);
		data_mllc = data;
	}
	new_node->data = data_mllc;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
