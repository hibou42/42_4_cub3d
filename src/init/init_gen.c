/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:05:06 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/12 11:09:25 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_gen(t_cube * cube, int ac, char **av)
{
	init_struct(cube);
	check_arg(ac, av);
	add_read_arg(cube, av);
	parsing(cube);
	check_parsing(cube);
	update_map(cube);
	init_cl(cube);
	cube->game->px_scr = (cube->map->offset_x - ((cube->map->width / 2) * ZOOM)) + (cube->game->p_x * ZOOM);
	cube->game->py_scr = (cube->map->offset_y - ((cube->map->hight / 2) * ZOOM)) + (cube->game->p_y * ZOOM);
	printf("Init || px = %f | py = %f\n", cube->game->p_x, cube->game->p_y);
	printf("Init || p_x = %f | p_y = %f\n", cube->game->px_scr, cube->game->py_scr);
}