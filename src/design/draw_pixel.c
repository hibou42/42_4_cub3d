/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 08:34:28 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/20 11:10:43 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	draw_player(t_cube *cube);
static void	draw_map(t_cube *cube, char **map, int i, int j);
static void	draw_map2(t_cube *cube, int x, int y);
static void	draw_wall(t_cube *cube, int start_x, int start_y);

/* --------------- Window design --------------------*/
int	render(t_cube *cube)
{
	if (cube->mlx.mlx_win == NULL)
		return (ERROR);
	render2(cube);
	draw_map(cube, cube->map->maps, 0, 0);
	draw_player(cube);
	mlx_put_image_to_window(cube->mlx.mlx_ptr, cube->mlx.mlx_win,
		cube->img.mlx_img, 0, 0);
	return (0);
}

/* --------------- Draw player --------------------*/
static int	draw_player(t_cube *cube)
{
	int		x;
	int		y;
	double	px_scr;
	double	py_scr;

	px_scr = (cube->map->offset_x - ((cube->map->width / 2) * ZOOM))
		+ (cube->game->p_x * ZOOM);
	py_scr = (cube->map->offset_y - ((cube->map->hight / 2) * ZOOM))
		+ (cube->game->p_y * ZOOM);
	y = py_scr - 2;
	while (y < py_scr + 2)
	{
		x = px_scr - 2;
		while (x < px_scr + 2)
			img_pix_put(&(cube->img), x++, y, GREEN);
		y++;
	}
	return (0);
}

/* --------------- Draw map 2d --------------------*/
static void	draw_map(t_cube *cube, char **map, int i, int j)
{
	int		x;
	int		y;
	int		start_x;
	int		start_y;

	start_x = cube->map->offset_x - ((cube->map->width / 2) * ZOOM - 1);
	start_y = cube->map->offset_y - ((cube->map->hight / 2) * ZOOM - 1);
	draw_wall(cube, start_x, start_y);
	while (j < cube->map->hight)
	{
		i = 0;
		y = start_y + (ZOOM * j);
		while (i < cube->map->width)
		{
			x = start_x + (ZOOM * i);
			if (map[j][i] == '0')
				draw_map2(cube, x, y);
			i++;
		}
		j++;
	}
}

static void	draw_map2(t_cube *cube, int x, int y)
{
	double	x1;
	double	y1;

	y1 = y + 1;
	while (y1 <= y + (ZOOM - 1))
	{
		x1 = x + 1;
		while (x1 <= x + (ZOOM - 1))
			img_pix_put(&(cube->img), x1++, y1, BLACK);
		y1++;
	}
}

static void	draw_wall(t_cube *cube, int start_x, int start_y)
{
	int	x;
	int	y;

	y = start_y;
	while (y <= start_y + (cube->map->hight * ZOOM))
	{
		x = start_x;
		while (x <= start_x + (cube->map->width * ZOOM))
			img_pix_put(&(cube->img), x++, y, WHITE);
		y++;
	}
}
