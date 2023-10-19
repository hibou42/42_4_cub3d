/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:28:52 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/19 16:24:26 by aschaefe         ###   ########.fr       */
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
	node->ray_dir_x = 0;
	node->ray_dir_y = 0;
	node->perp_wall_dist = 0;
	node->side = 0;
	node->line_height = 0;
	node->draw_start = 0;
	node->draw_end = 0;
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
	node->wall_x = 0;
}
