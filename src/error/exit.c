/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:56:40 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/19 14:07:57 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_maps(t_cube *cube);
void	free_texture(t_cube *cube);
void	free_info(t_cube *cube);

int	close_window(t_cube *cube)
{
	if (cube->map->maps != NULL)
		free_maps(cube);
	free_texture(cube);
	free_info(cube);
	exit(1);
}

void	free_maps(t_cube *cube)
{
	int		i;

	i = 0;
	while (i < cube->map->hight)
	{
		free(cube->map->maps[i]);
		i++;
	}
	free(cube->map->maps);
	cube->map->maps = NULL;
}

void	free_texture(t_cube *cube)
{
	if (cube->mlx.path_no)
		free(cube->mlx.path_no);
	if (cube->mlx.path_so)
		free(cube->mlx.path_so);
	if (cube->mlx.path_we)
		free(cube->mlx.path_we);
	if (cube->mlx.path_ea)
		free(cube->mlx.path_ea);
	if (cube->mlx.texture_no)
		free(cube->mlx.texture_no);
	if (cube->mlx.texture_so)
		free(cube->mlx.texture_so);
	if (cube->mlx.texture_we)
		free(cube->mlx.texture_we);
	if (cube->mlx.texture_ea)
		free(cube->mlx.texture_ea);
}

void	free_info(t_cube *cube)
{
	t_info	*tmp;
	t_info	*last_tmp;

	tmp = cube->info;
	while (tmp)
	{
		if (tmp->str)
		{
			free(tmp->str);
			tmp->str = NULL;
			last_tmp = tmp;
			tmp = tmp->next;
			free(last_tmp);
		}
	}
}