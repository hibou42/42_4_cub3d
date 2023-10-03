/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:23:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/09/26 13:29:10 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    verbose(t_cube *cube)
{
    printf("START\n");

    /* 
	// list info print
	t_info	*tmp;
	tmp = cube->info;
	while (tmp)
	{
		printf("%s", tmp->str);
		tmp = tmp->next;
	}
	*/

	// all path print
	printf("NO = |%s|\n", cube->mlx.path_no);
	printf("SO = |%s|\n", cube->mlx.path_so);
	printf("WE = |%s|\n", cube->mlx.path_we);
	printf("EA = |%s|\n", cube->mlx.path_ea);
	int i = 0;
	while (cube->mlx.floor_color[i])
	{
		if (cube->mlx.floor_color[i] != NULL)
			printf("Floor %d = |%s|\n", i, cube->mlx.floor_color[i]);
		else
			printf("Floor ???\n");
		i++;
	}
	i = 0;
	while (cube->mlx.roof_color[i])
	{
		if (cube->mlx.roof_color[i] != NULL)
			printf("Roof %d = |%s|\n", i, cube->mlx.roof_color[i]);
		else
			printf("Roof ???\n");
		i++;
	}
    
    // map print
	i = 0;
    if (cube->map->maps)
	{
		while (cube->map->maps[i])
		{
			printf("%s\n", cube->map->maps[i]);
			i++;
		}
	}
	printf("\nEND\n");
}