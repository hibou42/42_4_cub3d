/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:53:08 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/06 08:34:30 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* --------------- MAC OS --------------------*/
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
#  define ZOOM_IN				4
#  define ZOOM_OUT				5


/* --------------- LINUX OS --------------------*/
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
#  define ZOOM_IN				4
#  define ZOOM_OUT				5
# endif

/* --------------- SPRITE --------------------*/
# define SPRITE		64

/* --------------- MAP TYPE --------------------*/
# define TYPE		2

/* --------------- WINDOW --------------------*/
# define WIN_WIDTH	1920
# define WIN_HIGHT	1080
# define WIN_NAME	"Cub3D"

/* --------------- COLORS --------------------*/
# define GREEN		0x7CFC00
# define RED		0x00960018
# define WHITE		0xFFFFFF
# define BLACK		0x00000

/* --------------- EXIT --------------------*/
# define SUCCESS	0
# define ERROR		1

/* --------------- INTERNAL LIBRARY --------------------*/
# include "./libft/libft.h"

/* --------------- EXTERNAL LIBRARY --------------------*/
# include <string.h>
# include <math.h>

/* --------------- STRUCTURES --------------------*/
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}		t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	**floor_color;
	char	**roof_color;

}		t_mlx;

typedef struct s_map
{
	char	**maps;
	int		width;
	int		hight;
	int		offset_x;
	int		offset_y;
	float	zoom;

}		t_map;

typedef struct s_game
{
	float	player_x;
	float	player_y;
	char	*direction;

}		t_game;

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
	struct s_game	*game;
	struct s_img	img;
	char			**cpy_data;

}		t_cube;

/* --------------- FUNCTIONS --------------------*/
/* --------------- Pixel --------------------*/
int		render(t_cube *data);

/* --------------- Parsing --------------------*/
void	parsing(t_cube *cube);
void	check_parsing(t_cube *cube);
void	add_info(t_cube *cube, char *str);
void	add_map(t_cube *cube, t_info *tmp);

/* --------------- Events --------------------*/
int		deal_key(int key, t_cube *cube);
int		mouse_handle(int mousekey, t_cube *cube);
int		close_window(t_cube *cube);

/* --------------- ? --------------------*/
int		is_empty(char *str);
int		is_only_nb(char *str);
int		game(int key, t_cube *cube);
void	free_maps(t_cube *cube);
void	start_mlx(t_cube *cube);
void	flood_feed(t_cube *cube);
void	update_map(t_cube *cube);
void	init_struct(t_cube *cube);
void	check_arg(int argc, char **argv);
void	add_read_arg(t_cube *cube, char **argv);

/* --------------- Verbose --------------------*/
void	verbose(t_cube *cube);


#endif
