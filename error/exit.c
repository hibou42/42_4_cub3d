/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:56:40 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/11 13:32:45 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_and_exit(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->y)
	{
		free(map->maps[i]);
		free(map->cpy_maps[i]);
		i++;
	}
	free(map->maps);
	free(map->cpy_maps);
	exit(0);
}

int	close_window(t_map *map)
{
	if (map->maps)
		free_and_exit(map);
	(void)map;
	exit(0);
}
