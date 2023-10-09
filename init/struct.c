/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/09 13:07:17 by nrossel          ###   ########.fr       */
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
	cube->map->offset_x = (WIN_WIDTH / 2);
	cube->map->offset_y = (WIN_HIGHT / 2);
	// cube->map->offset_x = WIN_WIDTH - (WIN_WIDTH / 8); // mini map (Valeur ZOOM ==>> 10)
	// cube->map->offset_y = (WIN_HIGHT / 8); // mini map
	info = (t_info *)malloc(sizeof(t_info));
	cube->info = info;
	cube->info->next = NULL;
	game = (t_game *)malloc(sizeof(t_game));
	cube->game = game;
	cube->game->direction = NULL;
}
