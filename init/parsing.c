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

#include "../cub3d.h"

/*
int		is_empty(char **argv)
{
	int		i;
	int		j;
	int		fd;
	int		res;
	char	*buffer;

	fd = open(argv[1], 0);
	buffer = get_next_line(fd);
	res = 1;
	i = 0;
	while (buffer)
	{
		j = 0;

	}
	return (res);
}
*/

void	parsing(t_cube *cube, char **argv)
{
	int		fd;
	char	*buffer;

	fd = open(argv[1], 0);
	buffer = get_next_line(fd);
	while (buffer)
	{

	}
	(void)cube;
	(void)argv;
}
