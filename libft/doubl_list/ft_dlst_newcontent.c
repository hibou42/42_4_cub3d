/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_newcontent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:20:14 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/10 17:00:45 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_node	*ft_dlst_newcontent(double *data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	if (data)
	{
		new_node->nb = *data;
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
