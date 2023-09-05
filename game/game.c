/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/13 16:29:48 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	deal_key(int key, t_cube *cube)
{
	if (key == LEFT_KEY || key == A_KEY)
	{
		//move(map, 0, -1);
		printf("Gauche\n");
	}
	if (key == DOWN_KEY || key == S_KEY)
	{
		//move(map, 1, 0);
		printf("Bas\n");
	}
	if (key == RIGHT_KEY || key == D_KEY)
	{
		//move(map, 0, 1);
		printf("Droite\n");
	}
	if (key == UP_KEY || key == W_KEY)
	{
		//move(map, -1, 0);
		printf("Haut\n");
	}
	if (key == ESC)
		close_window(cube);
}


int	game(int key, t_cube *cube)
{
	deal_key(key, cube);
	return (0);
}
