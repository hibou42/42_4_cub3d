/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:53:08 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/11 17:07:55 by aschaefe         ###   ########.fr       */
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
#  define Q_KEY					
#  define E_KEY					
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
#  define Q_KEY					
#  define E_KEY					
#  define ESC					65307
#  define ZOOM_IN				4
#  define ZOOM_OUT				5
# endif

/* --------------- SPRITE --------------------*/
# define SPRITE		64

/* --------------- MAP TYPE --------------------*/
# define TYPE		3

/* --------------- WINDOW --------------------*/
# define WIN_WIDTH	1920
# define WIN_HIGHT	1080
# define WIN_NAME	"Cub3D"
# define ZOOM		10

/* --------------- COLORS --------------------*/
# define GREEN		0x7CFC00
# define RED		0x00960018
# define WHITE		0xFFFFFF
# define BLACK		0x00000
# define GRAY		0xF0F0F2

/* --------------- EXIT --------------------*/
# define SUCCESS	0
# define ERROR		1

/* --------------- INTERNAL LIBRARY --------------------*/
# include "./libft/libft.h"

/* --------------- EXTERNAL LIBRARY --------------------*/
# include <string.h>
# include <math.h>

/* --------------- MATH INFO --------------------*/
# define PI		3,1415926535

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
	int		rgb_floor[3];
	char	**roof_color;
	int		rgb_roof[3];

}		t_mlx;

typedef struct s_map
{
	char	**maps;
	int		width;
	int		hight;
	int		offset_x;
	int		offset_y;

}		t_map;

typedef struct s_game
{
	double	player_x;
	double	player_y;
	char	*direction;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

}		t_game;

typedef struct s_cl
{
	double			nb;
	struct s_cl		*next;
}	t_cl;

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
	struct s_cl		*cl;
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
void	convert_char_to_int(t_cube *cube, int choice);

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
void	init_cl(t_cube *cube);

/* --------------- Verbose --------------------*/
void	verbose(t_cube *cube);










void	test(t_cube *cube);







#endif
