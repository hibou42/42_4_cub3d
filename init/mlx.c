/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/03 13:50:04 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_mlx(t_cube *cube)
{
	cube->mlx.mlx_ptr = mlx_init();
	cube->mlx.mlx_win = mlx_new_window(cube->mlx.mlx_ptr, WIN_WIDTH, WIN_HIGHT, WIN_NAME);
}