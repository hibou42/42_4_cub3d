/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/30 13:10:59 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void ft_move(int key, double speed, t_cube *cube);
static void ft_rot(int key, double speed, t_cube *cube);

int	deal_key(int key, t_cube *cube)
{
	double	speed;

	speed = 0.15;
	fprintf(stderr, "key = %d\n", key);
	if (key == W_KEY || key == S_KEY || key == A_KEY || key == D_KEY)
		ft_move(key, speed, cube);
	else if (key == RIGHT_KEY || key == LEFT_KEY)
		ft_rot(key, speed, cube);
	else if (key == ESC)
		close_window(cube);
	raycasting(cube);
	render(cube);
	return (0);
}

static void ft_move(int key, double speed, t_cube *cube)
{
	if (key == W_KEY)
		updown_key(key, cube, speed);
	if (key == S_KEY)
		updown_key(key, cube, speed);
	if (key == A_KEY)
	{
		if (cube->game->direction[0] == 'S' || cube->game->direction[0] == 'W')
			ft_left_right(D_KEY, speed, cube);
		else
			ft_left_right(A_KEY, speed, cube);
	}
	if (key == D_KEY)
	{
		if (cube->game->direction[0] == 'S' || cube->game->direction[0] == 'W')
			ft_left_right(A_KEY, speed, cube);
		else
			ft_left_right(D_KEY, speed, cube);
	}
}

static void ft_rot(int key, double speed, t_cube *cube)
{
	if (key == RIGHT_KEY)
	{
		if (cube->game->direction[0] == 'S' || cube->game->direction[0] == 'W')
			press_left_key(cube, speed);
		else
			press_right_key(cube, speed);
	}
	else if (key == LEFT_KEY)
	{
		if (cube->game->direction[0] == 'S' || cube->game->direction[0] == 'W')
			press_right_key(cube, speed);
		else
			press_left_key(cube, speed);
	}
}
