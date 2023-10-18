/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:28:52 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/18 16:13:10 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	raycasting(t_cube *cube)
{
	t_cl	*node;

	node = cube->cl;
	while (node)
	{
		init_zero(node);
		init_for_calc(cube, node);
		initial_step(cube, node);
		dda(cube, node);
		calc_final_ray(cube, node);
		node = node->next;
	}
}

void	init_zero(t_cl *node)
{
	node->cam_x = 0;
	node->side_x = 0;
	node->side_y = 0;
	node->step_x = 0;
	node->step_y = 0;
	node->delta_y = 0;
	node->delta_x = 0;
	node->hit = 0;
	node->map_x = 0;
	node->map_y = 0;
}

void	init_for_calc(t_cube *cube, t_cl *node)
{
	node->cam_x = 2 * node->index / (double)WIN_WIDTH - 1;
	node->ray_dir_x = cube->game->dir_x + (cube->game->plane_x * node->cam_x);
	node->ray_dir_y = cube->game->dir_y + (cube->game->plane_y * node->cam_x);
	node->delta_y = sqrt(1 + (node->ray_dir_x * node->ray_dir_x)
			/ (node->ray_dir_y * node->ray_dir_y));
	node->delta_x = sqrt(1 + (node->ray_dir_y * node->ray_dir_y)
			/ (node->ray_dir_x * node->ray_dir_x));
	node->map_x = (int)cube->game->p_x;
	node->map_y = (int)cube->game->p_y;
}
