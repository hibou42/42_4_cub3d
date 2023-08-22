/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:45:58 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/11 14:12:26 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	element_check(t_map *map, int x, int y)
{
	int	res;

	res = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->maps[y][x] != '1' && map->maps[y][x] != '0')
				if (map->maps[y][x] != 'P' && map->maps[y][x] != 'C')
					if (map->maps[y][x] != 'E')
						if (map->maps[y][x] != '\n' && map->maps[y][x] != '\0')
							res += 1;
			x++;
		}
		y++;
	}
	if (res > 0)
		ft_printf("Error\nIl y a un.des element.s qui n'existe.nt pas\n");
	return (res);
}

int	check2_continue(t_map *map, int player, int exit)
{
	int	res;

	res = 0;
	if (player != 1)
	{
		ft_printf("Error\nLe nombre de joueur n'est pas bon\n");
		res++;
	}
	if (exit != 1)
	{
		ft_printf("Error\nLe nombre de sortie n'est pas bon\n");
		res++;
	}
	if (map->nb_coin == 0)
	{
		ft_printf("Error\nIl n'y a rien a collecter\n");
		res++;
	}
	return (res);
}

int	element_check2(t_map *map, int x, int y)
{
	int	player;
	int	exit;
	int	res;

	res = 0;
	player = 0;
	exit = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->maps[y][x] == 'P')
				player++;
			if (map->maps[y][x] == 'C')
				map->nb_coin += 1;
			if (map->maps[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	res += check2_continue(map, player, exit);
	return (res);
}
