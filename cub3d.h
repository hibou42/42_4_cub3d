/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:53:08 by aschaefe          #+#    #+#             */
/*   Updated: 2023/10/31 10:55:29 by nrossel          ###   ########.fr       */
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
#  define Q_KEY					12
#  define E_KEY					14
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
#  define Q_KEY					113
#  define E_KEY					101
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
# define PI		3.1415926535

/* --------------- STRUCTURES --------------------*/
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		line_len;
	int		endian;
}		t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	*path_no;
	t_img	*texture_no;
	char	*path_so;
	t_img	*texture_so;
	char	*path_we;
	t_img	*texture_we;
	char	*path_ea;
	t_img	*texture_ea;
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

typedef struct s_point2d
{
	double	x;
	double	y;
	double	vx;
	double	vy;
	double	d_x;
	double	d_y;
}		t_point2d;

typedef struct s_game
{
	double	p_x;
	double	p_y;
	char	*direction;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}		t_game;

typedef struct s_cl
{
	double		index;
	double		ray_dir_x;
	double		ray_dir_y;
	double		perp_wall_dist;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		cam_x;
	double		side_x;
	double		side_y;
	int			step_x;
	int			step_y;
	double		delta_y;
	double		delta_x;
	int			hit;
	int			map_x;
	int			map_y;
	double		wall_x;
	struct s_cl	*next;
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
/* --------------- Visual --------------------*/
int			render(t_cube *data);
int			render2(t_cube *data);
void		img_pix_put(t_img *img, int x, int y, int color);

/* --------------- Parsing --------------------*/
void		parsing(t_cube *cube);
void		check_parsing(t_cube *cube);
void		add_info(t_cube *cube, char *str);
void		add_map(t_cube *cube, t_info *tmp);
void		check_arg(int argc, char **argv);
void		convert_char_to_int(t_cube *cube, int choice);
void		add_read_arg(t_cube *cube, char **argv);
int			is_empty(char *str);
int			is_only_nb(char *str);
void		free_maps(t_cube *cube);
void		start_mlx(t_cube *cube);
void		flood_feed(t_cube *cube);

/* --------------- Initialization --------------------*/
void		init_gen(t_cube *cube, int ac, char **av);
void		init_struct(t_cube *cube);
void		init_cl(t_cube *cube);
void		update_map(t_cube *cube);

/* --------------- Math --------------------*/
void		ft_delta(t_point2d *v);
double		ft_radian(double angle);
double		pyth(double a, double b);
double		ft_opp(double radian, double adj);
void		raycasting(t_cube *cube);
void		init_zero(t_cl *node);
void		init_for_calc(t_cube *cube, t_cl *node);
void		initial_step(t_cube *cube, t_cl *node);
void		dda(t_cube *cube, t_cl *node);
void		calc_final_ray(t_cube *cube, t_cl *node);
void		texture(t_cube *cube, t_cl *node);

/* --------------- Events --------------------*/
int		deal_key(int key, t_cube *cube);
void	lateral_move(int key, double speed, t_cube *cube);
void	updown_move(int key, t_cube *cube, double speed);
void	left_key(t_cube *cube);
void	right_key(t_cube *cube);
int		close_window(t_cube *cube);
void	free_info(t_cube *cube);

#endif
