/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:44:49 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/13 15:50:36 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	watch_e(t_map *map)
{
	if (map->cpy_maps[map->exit_y - 1][map->exit_x] == 'X')
		map->cpy_maps[map->exit_y][map->exit_x] = 'X';
	if (map->cpy_maps[map->exit_y + 1][map->exit_x] == 'X')
		map->cpy_maps[map->exit_y][map->exit_x] = 'X';
	if (map->cpy_maps[map->exit_y][map->exit_x - 1] == 'X')
		map->cpy_maps[map->exit_y][map->exit_x] = 'X';
	if (map->cpy_maps[map->exit_y][map->exit_x + 1] == 'X')
		map->cpy_maps[map->exit_y][map->exit_x] = 'X';
}
