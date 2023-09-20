/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/09/20 11:44:36 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		is_empty(char *str)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			res = 0;
		}
		i++;
	}
	return (res);
}

void	parsing(t_cube *cube, char **argv)
{
	int		fd;
	char	*buffer;

	fd = open(argv[1], 0);
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (is_empty(buffer) == 0)
		{
			printf("%s", buffer);
		}
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	close(fd);
	(void)cube;
}
