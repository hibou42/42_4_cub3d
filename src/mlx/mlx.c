/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/23 13:55:54 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	ft_mlx_hook(t_cube *cube);
t_img		*load_texture(t_cube *cube, char *path);

void	start_mlx(t_cube *cube)
{
	cube->mlx.mlx_ptr = mlx_init();
	cube->mlx.mlx_win = mlx_new_window(cube->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HIGHT, WIN_NAME);
	cube->img.mlx_img = mlx_new_image(cube->mlx.mlx_ptr, WIN_WIDTH, WIN_HIGHT);
	cube->img.addr = mlx_get_data_addr(cube->img.mlx_img,
			&cube->img.bpp, &cube->img.line_len, &cube->img.endian);
	cube->mlx.texture_no = load_texture(cube, cube->mlx.path_no);
	cube->mlx.texture_so = load_texture(cube, cube->mlx.path_so);
	cube->mlx.texture_we = load_texture(cube, cube->mlx.path_we);
	cube->mlx.texture_ea = load_texture(cube, cube->mlx.path_ea);
	ft_mlx_hook(cube);
}

t_img	*load_texture(t_cube *cube, char *path)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img));
	texture->width = 64;
	texture->height = 64;
	texture->mlx_img = mlx_xpm_file_to_image(cube->mlx.mlx_ptr,
			path, &texture->width, &texture->height);
	if (!texture->mlx_img)
	{
		free(texture);
		ft_printf("Error : Impossible de charger la texture\n");
		close_window(cube);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->mlx_img,
			&texture->bpp, &texture->line_len, &texture->endian);
	return (texture);
}

/* --------------- Hook/loop functions --------------------*/
static void	ft_mlx_hook(t_cube *cube)
{
	raycasting(cube);
	render(cube);
	mlx_hook(cube->mlx.mlx_win, 2, 1L << 0, deal_key, cube);
	mlx_hook(cube->mlx.mlx_win, 17, 1L << 0, close_window, cube);
}
