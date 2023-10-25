/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/12 14:42:07 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	creat_new_node(t_cube *cube, int i);

void	init_cl(t_cube *cube)
{
	t_cl	*cl;
	int		i;

	cl = (t_cl *)malloc(sizeof(t_cl));
	cl->index = 0;
	cl->next = NULL;
	cube->cl = cl;
	i = 1;
	while (i < WIN_WIDTH)
	{
		creat_new_node(cube, i);
		i++;
	}
}

void	creat_new_node(t_cube *cube, int i)
{
	t_cl	*new;
	t_cl	*tmp;

	new = (t_cl *)malloc(sizeof(t_cl));
	new->index = i;
	new->next = NULL;
	tmp = cube->cl;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
