/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:23 by aschaefe          #+#    #+#             */
/*   Updated: 2023/09/20 13:46:25 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_empty(char *str)
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

int	is_only_nb(char *str)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && ft_isdigit(str[i]) > 0)
		{
			if (ft_isdigit(str[i]) != 0)
				res = 0;
		}
		i++;
	}
	return (res);
}