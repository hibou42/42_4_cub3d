/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:05:06 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/12 13:19:52 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_gen(t_cube * cube, int ac, char **av)
{
	init_struct(cube);
	check_arg(ac, av);
	add_read_arg(cube, av);
	parsing(cube);
	check_parsing(cube);
	update_map(cube);
	init_cl(cube);
}