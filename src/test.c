/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/12 14:59:34 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	test(t_cube *cube)
{
	t_cl	*node;
	double cameraX;

	node = cube->cl;

	// NOTE POUR MOI
	// rayDirX; = node->rayDirX
	// rayDirY; = node->rayDirY
	// w = WIN_WIDTH;
	// x = node->index
	// dirX = cube->game->dir_x
	// planeX = cube->game->plane_x
	// posX = cube->game->p_x

	while (node)
	{
		cameraX = 2 * node->index / (double)WIN_WIDTH - 1; //x-coordinate in camera space
		node->rayDirX = cube->game->dir_x + cube->game->plane_x * cameraX;
		node->rayDirY = cube->game->dir_y + cube->game->plane_x * cameraX;

		//which box of the map we're in
		int mapX = (int)cube->game->p_x;
		int mapY = (int)cube->game->p_y;
		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		double deltaDistY = sqrt(1 + (node->rayDirX* node->rayDirX) / (node->rayDirY * node->rayDirY));
		double deltaDistX = sqrt(1 + (node->rayDirY * node->rayDirY) / (node->rayDirX * node->rayDirX));

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;


		 //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (node->rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (cube->game->p_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - cube->game->p_x) * deltaDistX;
		}
		if (node->rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (cube->game->p_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - cube->game->p_y) * deltaDistY;
		}

		//perform DDA
		int hit = 0; //was there a wall hit?
		
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				node->side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				node->side = 1;
			}
			//Check if ray has hit a wall

			if (cube->map->maps[mapY][mapX] == '1')
				hit = 1;
		}
		
		//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
		if(node->side == 0)
			node->perpWallDist = (sideDistX - deltaDistX);
		else
			node->perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		node->lineHeight = (int)(cube->map->hight / cube->cl->perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		node->drawStart = -node->lineHeight / 2 + cube->map->hight / 2;

		if(node->drawStart < 0)
			node->drawStart = 0;
		node->drawEnd = node->lineHeight / 2 + cube->map->hight / 2;
		if(node->drawEnd >= cube->map->hight)
			node->drawEnd = cube->map->hight - 1;

		node = node->next;
	}
}