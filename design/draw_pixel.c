/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 08:34:28 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/09 18:17:30 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		img_pix_put(t_img *img, int x, int y, int color);
static int	draw_player(t_cube *cube);
static void	draw_map(t_cube *cube, char **map);
static void	black_screen(t_img *img);
static void draw_wall(t_cube *cube, int start_x, int start_y);
static void	display_roof(t_img *img, int *color);
static void	display_floor(t_img *img, int *color);

/* --------------- Window design --------------------*/
int	render(t_cube *cube)
{
	if (cube->mlx.mlx_win == NULL)
		return (ERROR);
	black_screen(&(cube->img));
	display_roof(&(cube->img), cube->mlx.rgb_roof);
	display_floor(&(cube->img), cube->mlx.rgb_floor);
	draw_map(cube, cube->map->maps);
	draw_player(cube);
	mlx_put_image_to_window(cube->mlx.mlx_ptr, cube->mlx.mlx_win,
		cube->img.mlx_img, 0, 0);
	return (0);
}

/* --------------- Draw pixel --------------------*/
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

/* --------------- Draw player --------------------*/
static int	draw_player(t_cube *cube)
{
	int	x;
	int	y;
	int	p_x;
	int	p_y;
	int	start_mapx;
	int	start_mapy;

	start_mapx = cube->map->offset_x - ((cube->map->width / 2) * ZOOM);
	start_mapy = cube->map->offset_y - ((cube->map->hight / 2) * ZOOM);
	p_x = start_mapx + (cube->game->player_x * ZOOM);
	p_y = start_mapy + (cube->game->player_y * ZOOM);
	// p_x = start_mapx + (cube->game->player_x * ZOOM + (ZOOM / 2));
	// p_y = start_mapy + (cube->game->player_y * ZOOM + (ZOOM / 2));
	y = p_y - 2;
	while (y < p_y + 2)
	{
		x = p_x - 2;
		while (x < p_x + 2)
			img_pix_put(&(cube->img), x++, y, GREEN);
		y++;
	}
	
	return (0);
}

/* --------------- Draw map 2d --------------------*/
static void	draw_map(t_cube *cube, char **map)
{
	int		i;
	int		j;
	int		x;
	int		y;
	double	x1;
	double	y1;
	int		start_x;
	int		start_y;	
	start_x = cube->map->offset_x - ((cube->map->width / 2) * ZOOM - 1);
	start_y = cube->map->offset_y - ((cube->map->hight / 2) * ZOOM - 1);
	j = 0;
	draw_wall(cube, start_x, start_y);
	while (j < cube->map->hight)
	{
		i = 0;
		y = start_y + (ZOOM * j);
		while (i < cube->map->width)
		{
			x = start_x + (ZOOM * i);
			if (map[j][i] == '0')
			{
				y1 = y + 1;
				while (y1 <= y + (ZOOM - 1))
				{
					x1 = x + 1;
					while (x1 <= x + (ZOOM - 1))
						img_pix_put(&(cube->img), x1++, y1, BLACK);
					y1++;
				}
			}
			i++;
		}
		j++;
	}
}

static void draw_wall(t_cube *cube, int start_x, int start_y)
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

/* --------------- Roof --------------------*/
static void	display_roof(t_img *img, int color[])
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

/* --------------- Floor --------------------*/
static void	display_floor(t_img *img, int color[])
{
	int	x;
	int	y;
	int	f_color;

	x = 0;
	y = WIN_HIGHT / 2;
	f_color = (color[0] * 65536) + (color[1] * 256) + color[2];
	while (y <= WIN_HIGHT)
	{
		x = 0;
		while (x <= WIN_WIDTH)
			img_pix_put(img, x++, y, f_color);
		y++;
	}
}

