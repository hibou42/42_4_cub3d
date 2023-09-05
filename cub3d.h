/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:53:08 by aschaefe          #+#    #+#             */
/*   Updated: 2023/01/13 15:48:09 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# if defined(__APPLE__) && defined(__MACH__)
#  include "./mlx/mlx.h"
#  define LEFT_KEY				123
#  define DOWN_KEY				125
#  define RIGHT_KEY				124
#  define UP_KEY				126
#  define A_KEY					0
#  define S_KEY					1
#  define D_KEY					2
#  define W_KEY					13
#  define ESC 					53

# else
#  include "./mlx-linux/mlx.h"
#  define LEFT_KEY				65361
#  define DOWN_KEY				65364
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define A_KEY					97
#  define S_KEY					115
#  define D_KEY					100
#  define W_KEY					119
#  define ESC					65307
# endif

# define SPRITE					64

# include "./libft/libft.h"

typedef struct s_cube
{
	void	*mlx;
	void	*mlx_win;
	char	**maps;
	int		map_x;
	int		map_y;
	int		pos_x;
	int		pos_y;
	void	*img_ground;
	void	*img_wall;
	void	*img_player;
	void	*img_coin;
	void	*img_exit_empty;
	void	*img_exit_full;
	int		img_x;
	int		img_y;

}		t_cube;

void	check_arg(int argc, char **argv);
void	parsing(t_cube *cube, char **argv);
void    check_parsing(t_cube *cube);
//void	init_img(t_map *map);
void	push_img(t_cube *cube, int x, int y, void *img);
int		game(int key, t_cube *cube);
int		close_window(t_cube *cube);

#endif