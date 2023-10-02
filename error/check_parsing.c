/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:37:51 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/02 16:54:18 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		is_valid_path(char *path);
int		is_valid_ext(char *path);
int		is_valid_color(char **tab);
void	dead_path_color(t_cube *cube, int choice);

void	check_parsing(t_cube *cube)
{
	if (is_valid_path(cube->mlx.path_no) != 0)
		dead_path_color(cube, 0);
	if (is_valid_path(cube->mlx.path_no) != 0)
		dead_path_color(cube, 0);
	if (is_valid_path(cube->mlx.path_no) != 0)
		dead_path_color(cube, 0);
	if (is_valid_path(cube->mlx.path_no) != 0)
		dead_path_color(cube, 0);
	if (is_valid_color(cube->mlx.floor_color) != 0)
		dead_path_color(cube, 1);
	if (is_valid_color(cube->mlx.roof_color) != 0)
		dead_path_color(cube, 1);
	check_parsing2(cube);
}

int		is_valid_path(char *path)
{
	int 	fd;
	int		read_ret;
	char	*buffer;
	
	if (path != NULL)
	{
		fd = open(path, 0);
		read_ret = read(fd, &buffer, 2);
		close(fd);
		if (read_ret > 0 && is_valid_ext(path) == 0)
		{
			return (0);
		}
		else
		{
			return (1);
		}
	}
	else
		return (1);
}

int		is_valid_ext(char *path)
{
	int	size;
	int	res;

	size = 0;
	while (path[size] != '\0')
		size ++;
	res = 0;
	if (path[size - 4] != '.')
		res = 1;
	if (path[size - 3] != 'x')
		res = 1;
	if (path[size - 2] != 'p')
		res = 1;
	if (path[size - 1] != 'm')
		res = 1;
	return (res);
}

int		is_valid_color(char **tab)
{
	int	size;
	int	tmp;

	size = 0;
	while (tab[size])
		size++;
	if (size != 3)
		return (1);
	if (is_only_nb(tab[0]) != 0)
		return (1);
	tmp = ft_atoi(tab[0]);
	if (tmp > 255 || tmp < 0)
		return (1);
	if (is_only_nb(tab[1]) != 0)
		return (1);
	tmp = ft_atoi(tab[1]);
	if (tmp > 255 || tmp < 0)
		return (1);
	if (is_only_nb(tab[2]) != 0)
		return (1);
	tmp = ft_atoi(tab[2]);
	if (tmp > 255 || tmp < 0)
		return (1);
	return (0);
}

void	dead_path_color(t_cube *cube, int choice)
{
	if (choice == 0)
	{
		ft_printf("Error : Texture path have problem\n");
		close_window(cube);
	}
	if (choice == 1)
	{
		ft_printf("Error : Wrong color\n");
		close_window(cube);
	}
}
