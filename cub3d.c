/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/09/20 12:08:53 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	cube = (t_cube){};
	init_struct(&cube);
	check_arg(argc, argv);
	add_read_arg(&cube, argv);
	parsing(&cube);
	verbose(&cube);
	check_parsing(&cube);
	start_mlx(&cube);
	mlx_key_hook(cube.mlx.mlx_win, game, &cube);
	mlx_hook(cube.mlx.mlx_win, 17, 1L << 0, close_window, &cube);
	mlx_loop(cube.mlx.mlx_ptr);
	close_window(&cube);
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