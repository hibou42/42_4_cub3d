/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 08:34:28 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/06 08:24:23 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		img_pix_put(t_img *img, int x, int y, int color);
static int	draw_player(t_cube *cube, int zoom);
static void	draw_map(t_cube *cube, char **map, int zoom);
static void	black_screen(t_img *img);

/* --------------- Window design --------------------*/
int	render(t_cube *cube)
{
	if (cube->mlx.mlx_win == NULL)
		return (ERROR);
	black_screen(&(cube->img));
	draw_map(cube, cube->map->maps, cube->map->zoom);
	draw_player(cube, cube->map->zoom);
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
static int	draw_player(t_cube *cube, int zoom)
{
	int	i;
	int	j;
	int	pos_player_x;
	int	pos_player_y;
	int	start_mapx;
	int	start_mapy;

	start_mapx = cube->map->offset_x - ((cube->map->width / 2) * zoom);
	start_mapy = cube->map->offset_y - ((cube->map->hight / 2) * zoom);
	pos_player_x = start_mapx + (cube->game->player_x * zoom);
	pos_player_y = start_mapy + (cube->game->player_y * zoom);
	j = pos_player_y - (zoom / 10);
	while (j < pos_player_y + 2)
	{
		i = pos_player_x - (zoom / 10);
		while (i < pos_player_x + 2)
			img_pix_put(&(cube->img), i++, j, GREEN);
		j++;
	}
	
	return (0);
}

/* --------------- Draw map 2d --------------------*/
static void	draw_map(t_cube *cube, char **map, int zoom)
{
	int		i;
	int		j;
	int		x;
	int		y;
	float	x1;
	float	y1;
	int		start_x;
	int		start_y;
	
	start_x = cube->map->offset_x - ((cube->map->width / 2) * zoom - 1);
	start_y = cube->map->offset_y - ((cube->map->hight / 2) * zoom - 1);
	if (TYPE == 1)
	{
		j = 0;
		while (j < cube->map->hight)
		{
			i = 0;
			y = start_y + (zoom * j);
			while (i < cube->map->width)
			{
				x = start_x + (zoom * i);
				if (map[j][i] == '0')
				{
					y1 = y - (zoom / 2);
					while (y1 < y + (zoom / 2))
					{
						x1 = x - (zoom / 2);
						while (x1 < x + (zoom / 2))
							img_pix_put(&(cube->img), x1++, y1, BLACK);
						y1++;
					}
				}
				else if (map[j][i] == '1')
				{
					y1 = y - (zoom / 2);
					while (y1 < y + (zoom / 2))
					{
						x1 = x - (zoom / 2);
						while (x1 < x + (zoom / 2))
							img_pix_put(&(cube->img), x1++, y1, WHITE);
						y1++;
					}
				}
				img_pix_put(&(cube->img), x, y, RED);
				i++;
			}
			j++;
		}
	}
	else if (TYPE == 2)
	{
		j = 0;
		while (j < cube->map->hight)
		{
			i = 0;
			y = start_y + (zoom * j);
			while (i < cube->map->width)
			{
				x = start_x + (zoom * i);
				if (map[j][i] == '0')
				{
					y1 = y;
					while (y1 < y + zoom)
					{
						x1 = x;
						while (x1 < x + zoom)
							img_pix_put(&(cube->img), x1++, y1, BLACK);
						y1++;
					}
				}
				else if (map[j][i] == '1')
				{
					y1 = y;
					while (y1 < y + zoom)
					{
						x1 = x;
						while (x1 < x + zoom)
							img_pix_put(&(cube->img), x1++, y1, WHITE);
						y1++;
					}
				}
				img_pix_put(&(cube->img), x, y, RED);
				i++;
			}
			j++;
		}
	}
	
}

/* --------------- Refresh black screen --------------------*/
static void	black_screen(t_img *img)
{
	int	x;
	int	y;
	int color;

	x = 0;
	y = 0;
	color = BLACK;
	while (y <= WIN_HIGHT)
	{
		x = 0;
		while (x <= WIN_WIDTH)
			img_pix_put(img, x++, y, color);
		y++;
	}
}
