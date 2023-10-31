/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:36:59 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/31 10:57:37 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	updown_move(int key, t_cube *cube, double speed)
{
	double	p_x;
	double	p_y;

	p_x = cube->game->p_x;
	p_y = cube->game->p_y;
	if (key == W_KEY)
	{
		if (cube->map->maps[(int)p_y][(int)(p_x + (cube->game->dir_x * speed))]
				== '0')
			cube->game->p_x += cube->game->dir_x * speed;
		if (cube->map->maps[(int)(p_y + (cube->game->dir_y * speed))][(int)p_x]
				== '0')
			cube->game->p_y += cube->game->dir_y * speed;
	}
	else
	{
		if (cube->map->maps[(int)p_y][(int)(p_x - (cube->game->dir_x * speed))]
				== '0')
				cube->game->p_x -= cube->game->dir_x * speed;
		if (cube->map->maps[(int)(p_y - (cube->game->dir_y * speed))][(int)p_x]
				== '0')
			cube->game->p_y -= cube->game->dir_y * speed;
	}
}

void	lateral_move(int key, double speed, t_cube *cube)
{
	double	p_x;
	double	p_y;

	p_x = cube->game->p_x;
	p_y = cube->game->p_y;
	if (key == A_KEY)
	{
		if (cube->map->maps[(int)p_y][(int)(p_x + (cube->game->dir_y
				* (speed * 2)))] == '0')
			cube->game->p_x += cube->game->dir_y * speed;
		if (cube->map->maps[(int)(p_y - (cube->game->dir_x
					* (speed * 2)))][(int)(p_x)] == '0')
			cube->game->p_y -= cube->game->dir_x * speed;
	}
	else if (key == D_KEY)
	{
		if (cube->map->maps[(int)(p_y)][(int)(p_x - (cube->game->dir_y
					* (speed * 2)))] == '0')
			cube->game->p_x -= cube->game->dir_y * speed;
		if (cube->map->maps[(int)(p_y + (cube->game->dir_x
					* (speed * 2)))][(int)p_x] == '0')
			cube->game->p_y += cube->game->dir_x * speed;
	}
}

void	left_key(t_cube *cube)
{
	double	old_dirx;
	double	old_planex;
	double	speed;

	speed = 0.05;
	old_dirx = cube->game->dir_x;
	cube->game->dir_x = cube->game->dir_x * cos(-speed)
		- cube->game->dir_y * sin(-speed);
	cube->game->dir_y = old_dirx * sin(-speed)
		+ cube->game->dir_y * cos(-speed);
	old_planex = cube->game->plane_x;
	cube->game->plane_x = cube->game->plane_x * cos(-speed)
		- cube->game->plane_y * sin(-speed);
	cube->game->plane_y = old_planex * sin(-speed)
		+ cube->game->plane_y * cos(-speed);
}

void	right_key(t_cube *cube)
{
	double	old_dirx;
	double	old_planex;
	double	speed;

	speed = 0.05;
	old_dirx = cube->game->dir_x;
	cube->game->dir_x = cube->game->dir_x * cos(speed)
		- cube->game->dir_y * sin(speed);
	cube->game->dir_y = old_dirx * sin(speed)
		+ cube->game->dir_y * cos(speed);
	old_planex = cube->game->plane_x;
	cube->game->plane_x = cube->game->plane_x * cos(speed)
		- cube->game->plane_y * sin(speed);
	cube->game->plane_y = old_planex * sin(speed)
		+ cube->game->plane_y * cos(speed);
}
