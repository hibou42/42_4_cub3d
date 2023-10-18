/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:28:52 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/18 16:13:40 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	initial_step(t_cube *cube, t_cl *node)
{
	if (node->ray_dir_x < 0)
	{
		node->step_x = -1;
		node->side_x = (cube->game->p_x - node->map_x) * node->delta_x;
	}
	else
	{
		node->step_x = 1;
		node->side_x = (node->map_x + 1.0 - cube->game->p_x) * node->delta_x;
	}
	if (node->ray_dir_y < 0)
	{
		node->step_y = -1;
		node->side_y = (cube->game->p_y - node->map_y) * node->delta_y;
	}
	else
	{
		node->step_y = 1;
		node->side_y = (node->map_y + 1.0 - cube->game->p_y) * node->delta_y;
	}
}

void	dda(t_cube *cube, t_cl *node)
{
	while (node->hit == 0)
	{
		if (node->side_x < node->side_y)
		{
			node->side_x += node->delta_x;
			node->map_x += node->step_x;
			node->side = 0;
		}
		else
		{
			node->side_y += node->delta_y;
			node->map_y += node->step_y;
			node->side = 1;
		}
		if (cube->map->maps[node->map_y][node->map_x] == '1')
			node->hit = 1;
	}
}

void	calc_final_ray(t_cube *cube, t_cl *node)
{
	if (node->side == 0)
	{
		node->perp_wall_dist = (node->map_x - cube->game->p_x
				+ (1 - node->step_x) / 2) / node->ray_dir_x;
	}
	else
	{
		node->perp_wall_dist = (node->map_y - cube->game->p_y
				+ (1 - node->step_y) / 2) / node->ray_dir_y;
	}
	node->line_height = (int)(WIN_HIGHT / node->perp_wall_dist);
	node->draw_start = (((-node->line_height) / 2) + (WIN_HIGHT / 2));
	if (node->draw_start < 0)
		node->draw_start = 0;
	node->draw_end = ((node->line_height / 2) + (WIN_HIGHT / 2));
	if (node->draw_end >= WIN_HIGHT)
		node->draw_end = WIN_HIGHT - 1;
}
