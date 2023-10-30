/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:36:59 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/30 13:12:10 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	updown_key(int key, t_cube *cube, double speed)
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

void	ft_left_right(int key, double speed, t_cube *cube)
{
	double	p_x;
	double	p_y;

	p_x = cube->game->p_x;
	p_y = cube->game->p_y;
	if (key == A_KEY)
	{
		if (cube->map->maps[(int)p_y][(int)(p_x + (cube->game->dir_y * (speed * 2)))]
				== '0')
			cube->game->p_x += cube->game->dir_y * speed;
		if (cube->map->maps[(int)(p_y - (cube->game->dir_x * (speed * 2)))][(int)(p_x)]
				== '0')
			cube->game->p_y -= cube->game->dir_x * speed;
	}
	else if (key == D_KEY)
	{
		if (cube->map->maps[(int)(p_y)][(int)(p_x - (cube->game->dir_y * (speed * 2)))]
				== '0')
			cube->game->p_x -= cube->game->dir_y * speed;
		if (cube->map->maps[(int)(p_y + (cube->game->dir_x * (speed * 2)))][(int)p_x]
				== '0')
			cube->game->p_y += cube->game->dir_x * speed;
	}
}

void	press_left_key(t_cube *cube, double speed)
{
	double	old_dirx;
	double	old_planex;

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

void	press_right_key(t_cube *cube, double speed)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = cube->game->dir_x;
	cube->game->dir_x = cube->game->dir_x * cos(speed)
		- cube->game->dir_y * sin(speed);
	cube->game->dir_y = old_dirx * sin(speed) + cube->game->dir_y * cos(speed);
	old_planex = cube->game->plane_x;
	cube->game->plane_x = cube->game->plane_x * cos(speed)
		- cube->game->plane_y * sin(speed);
	cube->game->plane_y = old_planex * sin(speed)
		+ cube->game->plane_y * cos(speed);
}
