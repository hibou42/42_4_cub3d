/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/02 17:32:52 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			x++;
		}
		y++;
	}
	if (cube->game->direction == NULL)
		problem(cube, 2);
}

void	add_player_in_struct2(t_cube *cube, int x, int y, char *direction)
{
	cube->game->player_x = x;
	cube->game->player_y = y;
	cube->game->direction = ft_substr(direction, 0, 1);
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
