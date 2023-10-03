/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 08:34:28 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/03 12:43:46 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color);
int		draw_player(t_cube *data, int player_x, int payer_y);
void	black_screen(t_img *img);

/* --------------- Window design --------------------*/
int	render(t_cube *data)
{
	if (data->mlx.mlx_win == NULL)
		return (ERROR);
	// draw_map();
	draw_player(data, data->game->player_x, data->game->player_y);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win,
		data->img.mlx_img, 0, 0);
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
int	draw_player(t_cube *data, int player_x, int player_y)
{
	int	i;
	int	j;
	
	black_screen(&(data->img));
	i = player_y - 3;
	while (i < player_y + 3)
	{
		j = player_x - 3;
		while (j < player_x + 3)
			img_pix_put(&(data->img), j++, i, GREEN);
		i++;
	}
	
	return (0);
}

/* --------------- Draw map 2d --------------------*/
// int	draw_map(t_cube data, char **map)
// {
// 	int	j;
// 	int	i;
// 	int	x;
// 	int	y;
	
// 	j = 0;
// 	x = WIN_WIDTH / 4;
// 	y = WIN_HIGHT / 4;
// 	while (map[j])
// 	{
// 		i = 0;
// 		while (j < data.map.x)
// 		{
// 			if (map[j][i] == 2)
// 			{
// 				int x1;
// 				int y1;
// 				y1 = y;
// 				while (y1 < y + 49)
// 				{
// 					x1 = x + 1;
// 					while (x1 < x + 49)
// 						img_pix_put(&(data.img), x1++, y1, RED);
// 					y1++;
// 				}
// 			}
// 			else if (map[j][i] == 1)
// 			{
// 				int x1;
// 				int y1;
// 				y1 = y;
// 				while (y1 < y + 49)
// 				{
// 					x1 = x + 1;
// 					while (x1 < x + 49)
// 						img_pix_put(&(data.img), x1++, y1, WHITE);
// 					y1++;
// 				}
// 			}
// 			else
// 			{
// 				int x1;
// 				int y1;
// 				y1 = y;
// 				while (y1 < y + 49)
// 				{
// 					x1 = x + 1;
// 					while (x1 < x + 49)
// 						img_pix_put(&(data.img), x1++, y1, BLACK);
// 					y1++;
// 				}
// 			}
// 		y += 50;
// 		}
// 	}
// }

/* --------------- Refresh black screen --------------------*/
void	black_screen(t_img *img)
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
