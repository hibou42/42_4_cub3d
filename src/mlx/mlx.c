/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/17 14:10:11 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	ft_mlx_hook(t_cube *cube);

void	start_mlx(t_cube *cube)
{
	cube->mlx.mlx_ptr = mlx_init();
	cube->mlx.mlx_win = mlx_new_window(cube->mlx.mlx_ptr, WIN_WIDTH, WIN_HIGHT, WIN_NAME);
	cube->img.mlx_img = mlx_new_image(cube->mlx.mlx_ptr, WIN_WIDTH, WIN_HIGHT);
	cube->img.addr = mlx_get_data_addr(cube->img.mlx_img, &cube->img.bpp, &cube->img.line_len, &cube->img.endian);
	ft_mlx_hook(cube);
}

/* --------------- Hook/loop functions --------------------*/
static void	ft_mlx_hook(t_cube *cube)
{
	render(cube);
	mlx_hook(cube->mlx.mlx_win, 2, 1L << 0, deal_key, cube);
	mlx_hook(cube->mlx.mlx_win, 17, 1L << 0, close_window, cube);
}