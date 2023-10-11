/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_read_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/11 14:21:19 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	add_new_chain(t_cube *cube, char *buffer);

void	add_read_arg(t_cube *cube, char **argv)
{
	int		fd;
	char	*buffer;

	fd = open(argv[1], 0);
	buffer = get_next_line(fd);
	cube->info->str = ft_strdup(buffer);
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
		if (buffer)
			add_new_chain(cube, buffer);
	}
	if (buffer)
		free(buffer);
	close(fd);
}

void    add_new_chain(t_cube *cube, char *buffer)
{
    t_info  *new;
    t_info  *tmp;

    new = (t_info *)malloc(sizeof(t_info));
    new->str = ft_strdup(buffer);
    new->next = NULL;
    tmp = cube->info;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}