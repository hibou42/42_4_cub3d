/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 08:34:28 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/30 13:17:55 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	display_floor(t_img *img, int *color);
static void	display_ceilling(t_img *img, int *color);
static void	display_fov(t_cube *cube);
static void	black_screen(t_img *img);

int	render2(t_cube *cube)
{
	black_screen(&(cube->img));
	display_floor(&(cube->img), cube->mlx.rgb_floor);
	display_ceilling(&(cube->img), cube->mlx.rgb_roof);
	display_fov(cube);
	return (0);
}

/* --------------- Refresh black screen --------------------*/
static void	black_screen(t_img *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= WIN_HIGHT)
	{
		x = 0;
		while (x <= WIN_WIDTH)
			img_pix_put(img, x++, y, BLACK);
		y++;
	}
}

/* --------------- Display floor --------------------*/
static void	display_floor(t_img *img, int color[])
{
	int	x;
	int	y;
	int	f_color;

	x = 0;
	y = 0;
	f_color = (color[0] * 65536) + (color[1] * 256) + color[2];
	y = WIN_HIGHT / 2;
	while (y <= WIN_HIGHT)
	{
		x = 0;
		while (x <= WIN_WIDTH)
			img_pix_put(img, x++, y, f_color);
		y++;
	}
}

/* --------------- Display ceilling --------------------*/
static void	display_ceilling(t_img *img, int color[])
{
	int	x;
	int	y;
	int	f_color;

	x = 0;
	y = 0;
	f_color = (color[0] * 65536) + (color[1] * 256) + color[2];
	while (y <= WIN_HIGHT / 2)
	{
		x = 0;
		while (x <= WIN_WIDTH)
			img_pix_put(img, x++, y, f_color);
		y++;
	}
}

/* --------------- Display FOW --------------------*/

static void	display_fov(t_cube *cube)
{
	t_cl	*tmp;

	tmp = cube->cl;
	while (tmp)
	{
		texture(cube, tmp);
		tmp = tmp->next;
	}
}
