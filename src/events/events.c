/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/23 13:56:41 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	deal_key(int key, t_cube *cube)
{
	double	speed;

	speed = 0.15;
	if ((key == UP_KEY || key == W_KEY))
		press_up_key(cube, speed);
	else if ((key == DOWN_KEY || key == S_KEY))
		press_down_key(cube, speed);
	else if ((key == RIGHT_KEY || key == D_KEY))
		press_right_key(cube, speed);
	else if ((key == LEFT_KEY || key == A_KEY))
		press_left_key(cube, speed);
	else if (key == ESC)
		close_window(cube);
	raycasting(cube);
	render(cube);
	return (0);
}

// int	deal_mouse(int key, t_cube *cube)
// {
// 	static int	pos;
// 	double		speed;

// 	printf("Mouse_key = %d\n", key);
// 	printf("pos = %d\n", pos);
// 	speed = 0.1;
// 	if (pos > key)
// 		press_left_key(cube, speed);
// 	else if (pos < key)
// 		press_right_key(cube, speed);
// 	pos = key;
// 	printf("Done !");
// 	raycasting(cube);
// 	render(cube);
// 	return (0);
// }
