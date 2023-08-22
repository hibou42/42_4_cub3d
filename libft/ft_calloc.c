/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:54:11 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/06 14:59:13 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Creat a malloc and set every byte at 0
		Return :
			the ptr
			NULL if failed
******************************************************************************/

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;

	ptr = malloc(nb * size);
	if (ptr)
	{
		ft_bzero(ptr, nb * size);
		return (ptr);
	}
	return (NULL);
}
