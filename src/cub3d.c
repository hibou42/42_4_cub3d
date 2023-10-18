/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/17 13:25:08 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_cube	cube;

	cube = (t_cube){};
	init_gen(&cube, ac, av);
	test(&cube);
	//verbose(&cube);
	start_mlx(&cube);
	mlx_loop(cube.mlx.mlx_ptr);
	mlx_destroy_image(cube.mlx.mlx_ptr, cube.img.mlx_img);
	mlx_destroy_window(cube.mlx.mlx_ptr, cube.mlx.mlx_win);
	free(cube.mlx.mlx_ptr);
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