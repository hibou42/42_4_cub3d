/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/02 14:33:45 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_struct(t_cube *cube)
{
	t_mlx	mlx;
	t_map	*map;
	t_info	*info;
	t_game	*game;

	mlx = (t_mlx){};
	cube->mlx = mlx;
	map = (t_map *)malloc(sizeof(t_map));
	cube->map = map;
	cube->map->maps = NULL;
	info = (t_info *)malloc(sizeof(t_info));
	cube->info = info;
	cube->info->next = NULL;
	game = (t_game *)malloc(sizeof(t_game));
	cube->game = game;
	cube->game->direction = NULL;
}
