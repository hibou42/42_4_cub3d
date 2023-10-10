/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/10 08:50:24 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_mlx_hook(t_cube *info);

int	main(int argc, char **argv)
{
	t_cube	cube;

	cube = (t_cube){};
	init_struct(&cube);
	check_arg(argc, argv);
	add_read_arg(&cube, argv);
	parsing(&cube);
	check_parsing(&cube);
	update_map(&cube);
	verbose(&cube);
	start_mlx(&cube);
	cube.img.mlx_img = mlx_new_image(cube.mlx.mlx_ptr, WIN_WIDTH, WIN_HIGHT);
	cube.img.addr = mlx_get_data_addr(cube.img.mlx_img, &cube.img.bpp, &cube.img.line_len, &cube.img.endian);
	ft_mlx_hook(&cube);
	close_window(&cube);
	return (0);
}

/* --------------- Hook/loop functions --------------------*/
static void	ft_mlx_hook(t_cube *cube)
{
	mlx_loop_hook(cube->mlx.mlx_ptr, &render, cube);
	mlx_hook(cube->mlx.mlx_win, 2, 1L << 0, deal_key, cube);
	// mlx_key_hook(cube->mlx.mlx_win, &deal_key, cube); // -->> Event KeyPress
	// mlx_mouse_hook(cube->mlx.mlx_win, &mouse_handle, cube); // -->> Event Mouse
	mlx_hook(cube->mlx.mlx_win, 17, 1L << 0, close_window, cube);
	mlx_loop(cube->mlx.mlx_ptr);
	mlx_destroy_image(cube->mlx.mlx_ptr, cube->img.mlx_img);
	mlx_destroy_window(cube->mlx.mlx_ptr, cube->mlx.mlx_win);
	free(cube->mlx.mlx_ptr);
	close_window(cube);
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