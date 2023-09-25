/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/09/20 16:13:42 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parsing(t_cube *cube)
{
	t_info	*tmp;

	tmp = cube->info;
	while (tmp)
	{
		if (is_empty(tmp->str) != 0)
		{
			if (is_only_nb(tmp->str) == 0)
			{
				add_map(cube, tmp);
				tmp->next = NULL;
			}
			else
				add_info(cube, tmp->str);
		}
		tmp = tmp->next;
	}
}
