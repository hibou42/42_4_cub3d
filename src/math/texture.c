/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:28:52 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/26 17:10:08 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	calc_texture(t_cube *cube, t_cl *node, t_img *texture, int y);
int		get_pixel(t_img *img, int x, int y);

void	texture(t_cube *cube, t_cl *node)
{
	t_img	*current_texture;

	if (node->side == 0)
	{
		if (node->ray_dir_x > 0)
			current_texture = cube->mlx.texture_ea;
		else
			current_texture = cube->mlx.texture_we;
	}
	else
	{
		if (node->ray_dir_y > 0)
			current_texture = cube->mlx.texture_so;
		else
			current_texture = cube->mlx.texture_no;
	}
	calc_texture(cube, node, current_texture, 0);
}

void	calc_texture(t_cube *cube, t_cl *node, t_img *texture, int y)
{
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;

	(void)cube;
	tex_x = (int)(node->wall_x * (double)texture->width);
	if (node->side == 0 && node->ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (node->side == 1 && node->ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	step = 1.0 * texture->height / node->line_height;
	tex_pos = (node->draw_start - WIN_HIGHT / 2 + node->line_height / 2) * step;
	y = node->draw_start;
	while (y < node->draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		color = get_pixel(texture, tex_x, tex_y);
		img_pix_put(&cube->img, node->index, y, color);
		tex_pos += step;
		y++;
	}
}

int	get_pixel(t_img *img, int x, int y)
{
	int	pos;
	int	color;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	pos = (y * img->line_len + x * (img->bpp / 8));
	color = *(unsigned int *)(img->addr + pos);
	return (color);
}
