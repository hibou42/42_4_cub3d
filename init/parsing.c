/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/13 16:26:55 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	write_x(t_map *map, int x, int y)
{
	int	res;

	res = 0;
	if (map->cpy_maps[y - 1][x] == '0' || map->cpy_maps[y - 1][x] == 'C' )
	{
		map->cpy_maps[y - 1][x] = 'X';
		res++;
	}
	if (map->cpy_maps[y + 1][x] == '0' || map->cpy_maps[y + 1][x] == 'C')
	{
		map->cpy_maps[y + 1][x] = 'X';
		res++;
	}
	if (map->cpy_maps[y][x - 1] == '0' || map->cpy_maps[y][x - 1] == 'C')
	{
		map->cpy_maps[y][x - 1] = 'X';
		res++;
	}
	if (map->cpy_maps[y][x + 1] == '0' || map->cpy_maps[y][x + 1] == 'C')
	{
		map->cpy_maps[y][x + 1] = 'X';
		res++;
	}
	return (res);
}

int	watch(t_map *map)
{
	int	x;
	int	y;
	int	res;

	res = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->cpy_maps[y][x] == 'X')
			{
				res += write_x(map, x, y);
			}
			x++;
		}
		y++;
	}
	return (res);
}

int	init_watch(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->cpy_maps[y][x] == 'P')
			{
				map->cpy_maps[y][x] = 'X';
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	last_check(t_map *map)
{
	int	x;
	int	y;
	int	res;

	res = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->cpy_maps[y][x] == 'C' || map->cpy_maps[y][x] == 'E')
			{
				res++;
			}
			x++;
		}
		y++;
	}
	return (res);
}

void	parsing(t_map *map)
{
	int	retour;

	retour = init_watch(map);
	while (retour != 0)
	{
		retour = watch(map);
	}
	watch_e(map);
	retour = last_check(map);
	if (retour != 0)
	{
		ft_printf("Error\nLa carte est impossible\n");
		close_window(map);
	}
}
