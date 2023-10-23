/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:56:40 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/23 16:48:37 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_maps(t_cube *cube);
void	free_texture(t_cube *cube);
void	free_info(t_cube *cube);
void	free_cl(t_cube *cube);

int	close_window(t_cube *cube)
{
	free_maps(cube);
	free_texture(cube);
	free_info(cube);
	free_cl(cube);
	exit(1);
}

void	free_maps(t_cube *cube)
{
	int		i;

	i = 0;
	if (cube->map->maps == NULL)
		return ;
	while (i < cube->map->hight)
	{
		free(cube->map->maps[i]);
		cube->map->maps[i] = NULL;
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
	t_info	*next_tmp;

	tmp = cube->info;
	while (tmp)
	{
		if (tmp->str)
		{
			free(tmp->str);
			tmp->str = NULL;
		}
		tmp = tmp->next;
	}
	tmp = cube->info;
	while (tmp)
	{
		next_tmp = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = next_tmp;
	}
	if (cube->game->direction)
		free(cube->game->direction);
}

void	free_cl(t_cube *cube)
{
	t_cl	*tmp;
	t_cl	*last_tmp;

	tmp = cube->cl;
	if (tmp)
	{
		while (tmp)
		{
			last_tmp = tmp;
			tmp = tmp->next;
			free(last_tmp);
		}
	}
}