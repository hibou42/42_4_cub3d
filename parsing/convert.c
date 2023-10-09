/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/09 18:18:49 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_floor(t_cube *cube);
void	ft_roof(t_cube *cube);
int		ft_tablen(char **tab);
void	problem2(t_cube *cube, int choice);

void	convert_char_to_int(t_cube *cube, int choice)
{
	if (choice == 1)
		ft_floor(cube);
	if (choice == 2)
		ft_roof(cube);
}

void	ft_floor(t_cube *cube)
{
	if (ft_tablen(cube->mlx.floor_color) != 3)
		problem2(cube, 1);
	if (is_only_nb(cube->mlx.floor_color[0]) != 0 
			&& is_only_nb(cube->mlx.floor_color[1]) != 0
				&& is_only_nb(cube->mlx.floor_color[2]) != 0)
		problem2(cube, 2);
	cube->mlx.rgb_floor[0] = ft_atoi(cube->mlx.floor_color[0]);
	cube->mlx.rgb_floor[1] = ft_atoi(cube->mlx.floor_color[1]);
	cube->mlx.rgb_floor[2] = ft_atoi(cube->mlx.floor_color[2]);
	if (cube->mlx.rgb_floor[0] > 255 || cube->mlx.rgb_floor[0] < 0)
		problem2(cube, 3);
	if (cube->mlx.rgb_floor[1] > 255 || cube->mlx.rgb_floor[1] < 0)
		problem2(cube, 3);
	if (cube->mlx.rgb_floor[2] > 255 || cube->mlx.rgb_floor[2] < 0)
		problem2(cube, 3);
}

void	ft_roof(t_cube *cube)
{
	if (ft_tablen(cube->mlx.roof_color) != 3)
		problem2(cube, 1);
	if (is_only_nb(cube->mlx.roof_color[0]) != 0
			&& is_only_nb(cube->mlx.roof_color[1]) != 0
				&& is_only_nb(cube->mlx.roof_color[2]) != 0)
		problem2(cube, 2);
	cube->mlx.rgb_roof[0] = ft_atoi(cube->mlx.roof_color[0]);
	cube->mlx.rgb_roof[1] = ft_atoi(cube->mlx.roof_color[1]);
	cube->mlx.rgb_roof[2] = ft_atoi(cube->mlx.roof_color[2]);
	if (cube->mlx.rgb_roof[0] > 255 || cube->mlx.rgb_roof[0] < 0)
		problem2(cube, 3);
	if (cube->mlx.rgb_roof[1] > 255 || cube->mlx.rgb_roof[1] < 0)
		problem2(cube, 3);
	if (cube->mlx.rgb_roof[2] > 255 || cube->mlx.rgb_roof[2] < 0)
		problem2(cube, 3);
}

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	problem2(t_cube *cube, int choice)
{
	if (choice == 1)
		ft_printf("Error : Wrong RGB layout\n");
	if (choice == 2)
		ft_printf("Error : Not only nb in RGB\n");
	if (choice == 3)
		ft_printf("Error : Wrong size of RGB\n");
	close_window(cube);
}
