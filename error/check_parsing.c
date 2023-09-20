/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:37:51 by aschaefe          #+#    #+#             */
/*   Updated: 2023/09/20 16:02:25 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_parsing(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->cpy_data[i])
	{
		printf("%s", cube->cpy_data[i]);
		i++;
	}
	(void)cube;
}