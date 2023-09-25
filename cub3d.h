/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:53:08 by aschaefe          #+#    #+#             */
/*   Updated: 2023/09/20 15:50:07 by aschaefe         ###   ########.fr       */
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

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		*floor_color;
	int		*roof_color;

}		t_mlx;

typedef struct s_map
{
	char	**maps;
	int		player_x;
	int		player_y;

}		t_map;

typedef struct s_info
{
	char			*str;
	struct s_info	*next;

}		t_info;

typedef struct s_cube
{
	struct s_mlx	mlx;
	struct s_map	*map;
	struct s_info	*info;
	char			**cpy_data;

}		t_cube;

void	check_arg(int argc, char **argv);
void	init_struct(t_cube *cube);
void	add_read_arg(t_cube *cube, char **argv);
void	parsing(t_cube *cube);
int		is_empty(char *str);
int		is_only_nb(char *str);
void	add_info(t_cube *cube, char *buffer);
void	add_map(t_cube *cube);
void	check_parsing(t_cube *cube);
void	start_mlx(t_cube *cube);
int		game(int key, t_cube *cube);
int		close_window(t_cube *cube);

#endif
