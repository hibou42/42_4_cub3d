/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:20:27 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/10 08:49:57 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_extension(char **argv);
int	is_access(char **argv);


void	check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\nVeuillez charger une seule fiche de donnees...\n");
		exit(1);
	}
	if (check_extension(argv) == 1)
	{
		ft_printf("Error\nProbleme d'extension de la fiche de donnees...\n");
		exit(1);
	}
	if (is_access(argv) == 1)
	{
		ft_printf("Error\nLa fiche de donnees n'est pas accessible...\n");
		exit(1);
	}
}

int	check_extension(char **argv)
{
	int	size_argv;
	int	res;

	size_argv = 0;
	while (argv[1][size_argv] != '\0')
		size_argv ++;
	res = 0;
	if (argv[1][size_argv - 4] != '.')
		res = 1;
	if (argv[1][size_argv - 3] != 'c')
		res = 1;
	if (argv[1][size_argv - 2] != 'u')
		res = 1;
	if (argv[1][size_argv - 1] != 'b')
		res = 1;
	return (res);
}

int		is_access(char **argv)
{
	int		fd;
	int		read_ret;
	int		res;
	char	*buffer;

	fd = open(argv[1], 0);
	read_ret = read(fd, &buffer, 2);
	if (read_ret < 0)
		res = 1;
	else
		res = 0;
	close(fd);
	return (res);
}
