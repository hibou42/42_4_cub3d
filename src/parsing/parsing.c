/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/10 08:49:57 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	add_player_in_struct(t_cube *cube);
void	add_player_in_struct2(t_cube *cube, int x, int y, char *direction);
void	problem(t_cube *cube, int choice);

void	parsing(t_cube *cube)
{
	t_info	*tmp;

	tmp = cube->info;
	while (tmp)
	{
		if (is_empty(tmp->str) != 0)
		{
			if (is_only_nb(tmp->str) == 0)
			{
				add_map(cube, tmp);
				tmp->next = NULL;
			}
			else
				add_info(cube, tmp->str);
		}
		tmp = tmp->next;
	}
	add_player_in_struct(cube);
}

void	add_player_in_struct(t_cube *cube)
{
	int		x;
	int		y;
	char	tmp;

	y = 0;
	while (y < cube->map->hight)
	{
		x = 0;
		while (cube->map->maps[y][x])
		{
			tmp = cube->map->maps[y][x];
			if (tmp == 'N' || tmp == 'S' || tmp == 'E' || tmp == 'W')
			{
				if (cube->game->direction == NULL)
					add_player_in_struct2(cube, x, y, &tmp);
				else
					problem(cube, 1);
			}
			else if (tmp == '0' || tmp == '1' || tmp == ' ')
				x++;
			else
				problem(cube, 3);
		}
		y++;
	}
	if (cube->game->direction == NULL)
		problem(cube, 2);
}

void	add_player_in_struct2(t_cube *cube, int x, int y, char *direction)
{
	char tmp;
	
	tmp = cube->map->maps[y][x];
	cube->game->player_x = x + 0.5;
	cube->game->player_y = y + 0.5;
	cube->game->direction = ft_substr(direction, 0, 1);
	if (tmp == 'N')
		cube->game->p_dir = 0;
	if (tmp == 'S')
		cube->game->p_dir = 180;
	if (tmp == 'E')
		cube->game->p_dir = 90;
	if (tmp == 'W')
		cube->game->p_dir = 270;
	cube->map->maps[y][x] = '0';
}

void	problem(t_cube *cube, int choice)
{
	if (choice == 1)
		ft_printf("Error : To many player on the map\n");
	if (choice == 2)
		ft_printf("Error : No player on the map\n");
	if (choice == 3)
		ft_printf("Error : Player bad position on the map\n");
	close_window(cube);
}
