/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_read_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/23 16:26:23 by nrossel          ###   ########.fr       */
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
	if (buffer)
		cube->info->str = ft_strdup(buffer);
	else
	{
		ft_printf("Error : La fiche de donnee est vide\n");
		close_window(cube);
	}
	while (buffer)
	{
		free(buffer);
		buffer = NULL;
		buffer = get_next_line(fd);
		if (buffer)
			add_new_chain(cube, buffer);
	}
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	close(fd);
}

void	add_new_chain(t_cube *cube, char *buffer)
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