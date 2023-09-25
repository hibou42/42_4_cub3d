/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:56:40 by aschaefe          #+#    #+#             */
/*   Updated: 2023/09/20 15:57:16 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_maps(t_cube *cube);
void	free_path(t_cube *cube);
void	free_info(t_cube *cube);

int	close_window(t_cube *cube)
{
	if (cube->map->maps != NULL)
		free_maps(cube);
	free_path(cube);
	free_info(cube);
	exit(1);
}

void	free_maps(t_cube *cube)
{
	int		i;

	i = 0;
	while (cube->map->maps[i])
	{
		free(cube->map->maps[i]);
		i++;
	}
	free(cube->map->maps);
}

void	free_path(t_cube *cube)
{
	if (cube->mlx.path_no)
		free(cube->mlx.path_no);
	if (cube->mlx.path_so)
		free(cube->mlx.path_so);
	if (cube->mlx.path_we)
		free(cube->mlx.path_we);
	if (cube->mlx.path_ea)
		free(cube->mlx.path_ea);
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