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

/*
	return 0 if the str is empty
	return 1 if the str have something
*/

int	is_empty(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			res = 1;
		i++;
	}
	return (res);
}

/*
	return 0 if the str is only number and space
	return 1 if the str have char
*/

int	is_only_nb(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] && res == 0)
	{
		if (str[i] != ' ' && str[i] != '\n' && ft_isalpha(str[i]) != 0)
				res = 1;
		i++;
	}
	return (res);
}