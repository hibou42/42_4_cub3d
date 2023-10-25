/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_feed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:37:51 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/10 08:49:57 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		check_flood_feed(t_cube *cube, int x, int y);

void	flood_feed(t_cube *cube)
{
	int	stop;
	int	x;
	int	y;

	y = 0;
	stop = 0;
	while (y < cube->map->hight)
	{
		x = 0;
		while (cube->map->maps[y][x])
		{
			if (cube->map->maps[y][x] == '0')
				stop += check_flood_feed(cube, x, y);
			x++;
		}
		y++;
	}
	if (stop > 0)
	{
		ft_printf("Error : La map n'est pas fermee\n");
		close_window(cube);
	}
}

int	check_flood_feed(t_cube *cube, int x, int y)
{
	int	x_max;

	x_max = ft_strlen(cube->map->maps[y]);
	if (y == 0 || y == cube->map->hight)
		return (1);
	if (x == 0 || x == x_max)
		return (1);
	if (cube->map->maps[y][x + 1] != '1' && cube->map->maps[y][x + 1] != '0')
		return (1);
	if (cube->map->maps[y][x - 1] != '1' && cube->map->maps[y][x - 1] != '0')
		return (1);
	if (cube->map->maps[y + 1][x] != '1' && cube->map->maps[y + 1][x] != '0')
		return (1);
	if (cube->map->maps[y - 1][x] != '1' && cube->map->maps[y - 1][x] != '0')
		return (1);
	return (0);
}
