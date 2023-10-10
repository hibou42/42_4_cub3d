/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/10 08:49:57 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static char	move_map(int key, char **map, double p_x, double p_y);

/*
void	move(t_map *map, int move_y, int move_x)
{
	char	next_case;

	next_case = map->maps[map->pos_y + move_y][map->pos_x + move_x];
	if (next_case == '0' || next_case == 'C' || next_case == 'P')
	{
		push_img(map, map->pos_x * SPRITE, \
			map->pos_y * SPRITE, map->img_ground);
		map->pos_x += move_x;
		map->pos_y += move_y;
		push_img(map, map->pos_x * SPRITE, \
			map->pos_y * SPRITE, map->img_player);
		if (next_case == 'C')
		{
			map->nb_coin--;
			map->maps[map->pos_y][map->pos_x] = '0';
		}
		map->step_cpt++;
		ft_printf("Step n°%d\n", map->step_cpt);
	}
	else if (next_case == 'V')
	{
		map->step_cpt++;
		ft_printf("Victory !!!\nVous l'avez fait en %d pas\n", map->step_cpt);
		close_window(map);
	}
}
*/

int	deal_key(int key, t_cube *cube)
{
	double	p_x;
	double	p_y;
	char		wall;

	printf("key = %d\n", key);
	p_x = cube->game->player_x;
	p_y = cube->game->player_y;
	wall = move_map(key, cube->map->maps, p_x, p_y);
	if ((key == LEFT_KEY || key == A_KEY) && wall == '0')
	{
		cube->game->player_x -= 0.1;
		printf("Gauche + %f\n", cube->game->player_x);
	}
	else if ((key == DOWN_KEY || key == S_KEY) && wall == '0')
	{
		cube->game->player_y += 0.1;
		printf("Bas + %f\n", cube->game->player_y);
	}
	else if ((key == RIGHT_KEY || key == D_KEY) && wall == '0')
	{
		cube->game->player_x += 0.1;
		printf("Droite + %f\n", cube->game->player_x);
	}
	else if ((key == UP_KEY || key == W_KEY) && wall == '0')
	{
		cube->game->player_y -= 0.1;
		printf("Haut + %f\n", cube->game->player_y);
	}
	else if (key == ESC)
		close_window(cube);
	return (0);
}

static char	move_map(int key, char **map, double p_x, double p_y)
{
	if (key == LEFT_KEY || key == A_KEY)
		return (map[(int)(p_y)][(int)(p_x - 0.1)]);
	else if (key == RIGHT_KEY || key == D_KEY)
		return (map[(int)(p_y)][(int)(p_x + 0.1)]);
	else if (key == UP_KEY || key == W_KEY)
		return (map[(int)(p_y - 0.1)][(int)p_x]);
	else if (key == DOWN_KEY || key == S_KEY)
		return (map[(int)(p_y + 0.1)][(int)p_x]);
	return ('E');
}


// int	mouse_handle(int mousekey, t_cube *cube)
// {
// 	if (mousekey == ZOOM_IN)
// 		cube->map->zoom += 5;
// 	else if (mousekey == ZOOM_OUT && cube->map->zoom > 0)
// 		cube->map->zoom -= 5;
// 	return (0);
// }
