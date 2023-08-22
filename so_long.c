/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/13 15:05:11 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_map *map)
{
	map->maps = NULL;
	map->x = 0;
	map->y = 0;
	map->nb_coin = 0;
	map->img_player = NULL;
	map->step_cpt = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	init_struct(&map);
	check_arg(argc, argv);
	init_map(argv, &map);
	parsing(&map);
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, map.x * SPRITE, \
		map.y * SPRITE, "So Long");
	init_img(&map);
	mlx_key_hook(map.mlx_win, game, &map);
	mlx_hook(map.mlx_win, 17, 1L << 0, close_window, &map);
	mlx_loop(map.mlx);
	return (0);
}

/*
Setup if mouse is needed :

mlx_mouse_hook(map.mlx_win, deal_mouse, (void*)0);
int	deal_mouse(int key)
{
	(void) key;
	return (0);
}
*/