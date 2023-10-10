/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:37:51 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/10 08:49:57 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int     find_max_x(t_cube *cube);
char    **creat_new_maps(t_cube *cube);
void    swap_new_maps(t_cube *cube, char **new_maps);

void    update_map(t_cube *cube)
{
    char    **new_maps;

    cube->map->width = find_max_x(cube);
    new_maps = creat_new_maps(cube);
    swap_new_maps(cube, new_maps);
    free_maps(cube);
    cube->map->maps = new_maps;
}

int     find_max_x(t_cube *cube)
{
    int res;
    int x;
    int y;

    res = 0;
    y = 0;
    while (y < cube->map->hight)
    {
        x = 0;
        while (cube->map->maps[y][x])
            x++;
        if (x > res)
            res = x;
        y++;
    }
    return (res);
}

char    **creat_new_maps(t_cube *cube)
{
    char    **new_maps;
    int     y;

    new_maps = malloc(cube->map->hight * sizeof(char *));
    y = 0;
    while (y < cube->map->hight)
    {
        new_maps[y] = malloc(cube->map->width * sizeof(char));
        y++;
    }
    return (new_maps);
}

void    swap_new_maps(t_cube *cube, char **new_maps)
{
    int     x;
    int     y;

    y = 0;
    while (y < cube->map->hight)
    {
        x = 0;
        while (cube->map->maps[y][x])
        {
            if (cube->map->maps[y][x] == ' ')
                new_maps[y][x] = '1';
            else
                new_maps[y][x] = cube->map->maps[y][x];
            x++;
        }
        if (x < cube->map->width)
        {
            while (x < cube->map->width)
            {
                new_maps[y][x] = '1';
                x++;
            }
        }
        y++;
    }
}