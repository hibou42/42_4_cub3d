/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/09/20 16:20:01 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_path(t_cube *cube, char *path_def, char *buffer);
void	add_tab(t_cube *cube, int *tab, char *buffer);

void	add_info(t_cube *cube, char *buffer)
{
	(void)cube;
	(void)buffer;
	/*
	if(buffer[0] == 'N')
		//add_path(cube, cube->mlx.path_no, buffer);
	else if (buffer[0] == 'S')
		//add_path(cube, cube->mlx.path_so, buffer);
	else if (buffer[0] == 'W')
		//add_path(cube, cube->mlx.path_we, buffer);
	else if (buffer[0] == 'E')
		//add_path(cube, cube->mlx.path_ea, buffer);
	else if (buffer[0] == 'F')
		//add_tab(cube, cube->mlx.floor_color, buffer);
	else if (buffer[0] == 'C')
		//add_tab(cube, cube->mlx.roof_color, buffer);
	else
	{
		ft_printf("Error : Une ligne fout le zbeul\n");
		close_window(cube);
	}
	*/
}

void	add_path(t_cube *cube, char *path_def, char *buffer)
{
	int	stop;

	stop = 0;
	if (path_def != NULL)
		stop = 1;
	else
	{
		path_def = ft_substr(buffer, 3, ft_strlen(buffer) - 3);
	}
	if (stop == 1)
	{
		ft_printf("Error : Probleme attribution de path\n");
		close_window(cube);
	}
}

void	add_tab(t_cube *cube, int *tab, char *buffer)
{
	(void)cube;
	(void)tab;
	(void)buffer;
}