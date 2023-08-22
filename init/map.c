/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:37:51 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/13 17:13:35 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_data_struct(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->maps[y][x] == 'P')
			{
				map->pos_x = x;
				map->pos_y = y;
			}
			if (map->maps[y][x] == 'E')
			{
				map->exit_x = x;
				map->exit_y = y;
			}
			x++;
		}
		y++;
	}
}

void	map_in_tab(char **argv, t_map *map)
{
	int		fd;
	int		i;

	map->maps = ft_calloc(map->y, sizeof(char *));
	fd = open(argv[1], 0);
	i = 0;
	while (i < map->y)
	{
		map->maps[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	cpy_map_in_tab(char **argv, t_map *map)
{
	int		fd;
	int		i;

	map->cpy_maps = ft_calloc(map->y, sizeof(char *));
	fd = open(argv[1], 0);
	i = 0;
	while (i < map->y)
	{
		map->cpy_maps[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	map_size(char **argv, t_map *map, int i)
{
	char	*tmp;
	int		fd;

	fd = open(argv[1], 0);
	if (fd == -1)
	{
		ft_printf("Error\nLa map n'est pas lisible ou trouvable\n");
		close_window(map);
	}
	tmp = get_next_line(fd);
	map->x = ft_strlen(tmp) - 1;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
	map->y = i - 1;
	close(fd);
	if ((map->x * SPRITE) > 1920 || (map->y * SPRITE) > 1080)
	{
		ft_printf("Error\nLa map est trop grande\n");
		close_window(map);
	}
}

void	init_map(char **argv, t_map *map)
{
	int		fd;
	int		read_ret;
	char	*buffer;

	fd = open(argv[1], 0);
	read_ret = read(fd, &buffer, 2);
	if (read_ret < 0)
	{
		ft_printf("Error\nLa carte n'est pas accessible\n");
		close(fd);
		close_window(map);
	}
	if (read_ret == 0)
	{
		ft_printf("Error\nLa carte est vide\n");
		close(fd);
		close_window(map);
	}
	close(fd);
	map_size(argv, map, 1);
	map_in_tab(argv, map);
	cpy_map_in_tab(argv, map);
	check_tab(map);
	add_data_struct(map);
}
