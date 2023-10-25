/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/23 16:17:47 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	nb_line(t_info *tmp);

void	add_map(t_cube *cube, t_info *tmp)
{
	int	size;
	int	i;

	size = nb_line(tmp);
	cube->map->hight = size;
	cube->map->maps = malloc(size * sizeof(char *));
	i = 0;
	while (tmp && is_empty(tmp->str) == 1)
	{
		cube->map->maps[i] = ft_strtrim(tmp->str, "\n");
		tmp = tmp->next;
		i++;
	}
}

int	nb_line(t_info *tmp)
{
	int	res;

	res = 0;
	while (tmp && is_empty(tmp->str) == 1)
	{
		tmp = tmp->next;
		res++;
	}
	return (res);
}
