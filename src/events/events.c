/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/19 17:08:43 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// static char	move_map(int key, char **map, double p_x, double p_y);

int	deal_key(int key, t_cube *cube)
{
	double	p_x;
	double	p_y;
	double	old_dirx;
	double	old_planex;
	double	rotSpeed;

	rotSpeed = 0.1;
	p_x = cube->game->p_x;
	p_y = cube->game->p_y;
	if ((key == UP_KEY || key == W_KEY))
	{
		if (cube->map->maps[(int)p_y][(int)(p_x + (cube->game->dir_x * 0.1))] == '0')
			p_x += cube->game->dir_x * 0.1;
		if (cube->map->maps[(int)(p_y + (cube->game->dir_y * 0.1))][(int)p_x] == '0')
			p_y += cube->game->dir_y * 0.1;
	}
	else if ((key == DOWN_KEY || key == S_KEY))
	{
		if (cube->map->maps[(int)p_y][(int)(p_x - (cube->game->dir_x * 0.1))] == '0')
			p_x -= cube->game->dir_x * 0.1;
		if (cube->map->maps[(int)(p_y - (cube->game->dir_y * 0.1))][(int)p_x] == '0')
			p_y -= cube->game->dir_y * 0.1;
	}
	else if ((key == RIGHT_KEY || key == D_KEY))
	{
		
	}
	else if ((key == LEFT_KEY || key == A_KEY))
	{
		
	}
	else if (key == E_KEY)
	{
		old_dirx = cube->game->dir_x;
		cube->game->dir_x = cube->game->dir_x * cos(rotSpeed) - cube->game->dir_y * sin(rotSpeed);
		cube->game->dir_y = old_dirx * sin(rotSpeed) + cube->game->dir_y * cos(rotSpeed);
		old_planex = cube->game->plane_x;
		cube->game->plane_x = cube->game->plane_x * cos(rotSpeed) - cube->game->plane_y * sin(rotSpeed);
		cube->game->plane_y = old_planex * sin(rotSpeed) + cube->game->plane_y * cos(rotSpeed);
	}
	else if (key == Q_KEY)
	{
		old_dirx = cube->game->dir_x;
		cube->game->dir_x = cube->game->dir_x * cos(-rotSpeed) - cube->game->dir_y * sin(-rotSpeed);
		cube->game->dir_y = old_dirx * sin(-rotSpeed) + cube->game->dir_y * cos(-rotSpeed);
		old_planex = cube->game->plane_x;
		cube->game->plane_x = cube->game->plane_x * cos(-rotSpeed) - cube->game->plane_y * sin(-rotSpeed);
		cube->game->plane_y = old_planex * sin(-rotSpeed) + cube->game->plane_y * cos(-rotSpeed);
	}
	else if (key == ESC)
		close_window(cube);
	raycasting(cube);
	render(cube);
	return (0);
}


