/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/09/20 16:13:42 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		how_many_line(char **argv);
void	copy_data(t_cube *cube, char **argv, int i);

void	parsing(t_cube *cube, char **argv)
{
	int	size;

	size = how_many_line(argv);
	copy_data(cube, argv, size);
	/*
		if (is_empty(buffer) == 0)
		{
			if (is_only_nb(buffer) == 0)
			{
				add_map(cube, i, argv);
				break;
			}
			else
				add_info(cube, buffer);
		}
		i++;
	*/
}

int		how_many_line(char **argv)
{
	int		fd;
	int		res;
	char	*buffer;

	fd = open(argv[1], 0);
	buffer = get_next_line(fd);
	res = 1;
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
		res++;
	}
	free(buffer);
	close(fd);
	return (res);
}

void	copy_data(t_cube *cube, char **argv, int size)
{
	int		fd;
	int		i;
	char	*buffer;

	cube->cpy_data = malloc((size) * sizeof (char*));
	fd = open(argv[1], 0);
	buffer = get_next_line(fd);
	i = 0;
	while (buffer)
	{
		cube->cpy_data[i] = ft_strdup(buffer);
		free(buffer);
		buffer = get_next_line(fd);
		i++;
	}
	cube->cpy_data[i] = ft_strdup("\0");
}
