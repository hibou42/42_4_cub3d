/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/11 16:29:07 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	wall_check2(t_map *map)
{
	int	res;
	int	i;

	res = 0;
	i = 1;
	while (i < map->y - 1)
	{
		if (map->maps[i][0] != '1' || map->maps[i][map->x - 1] != '1')
			res++;
		i++;
	}
	return (res);
}

int	wall_check(t_map *map)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (map->maps[0][i])
	{
		if (map->maps[0][i] != '1' && map->maps[0][i] != '\n')
			res = 1;
		i++;
	}
	res += wall_check2(map);
	i = 0;
	while (map->maps[map->y - 1][i])
	{
		if (map->maps[map->y - 1][i] != '1' && map->maps[map->y - 1][i] != '\n')
			res = 1;
		i++;
	}
	if (res == 1)
		ft_printf("Error\nLa carte n'est pas entouree de murs\n");
	return (res);
}

int	x_check(t_map *map)
{
	int	res;
	int	tmp;
	int	i;

	res = 0;
	i = 0;
	while (i < map->y)
	{
		tmp = ft_strlen(map->maps[i]) - 1;
		if (tmp != map->x)
			res = 1;
		i++;
	}
	if (res == 1)
		ft_printf("Error\nLa carte n'est pas rectangulaire\n");
	if (map->x < 3)
	{
		ft_printf("Error\nLa carte n'est pas asser large\n");
		res = 1;
	}
	return (res);
}

int	y_check(t_map *map)
{
	if (map->y < 3)
	{
		ft_printf("Error\nLa carte n'est pas asser haute\n");
		return (1);
	}
	return (0);
}

void	check_tab(t_map *map)
{
	int	res;

	res = 0;
	res += y_check(map);
	res += x_check(map);
	if (res > 0)
		close_window(map);
	res += element_check(map, 0, 0);
	res += element_check2(map, 0, 0);
	if (res > 0)
		close_window(map);
	res += wall_check(map);
	if (res > 0)
		close_window(map);
}
