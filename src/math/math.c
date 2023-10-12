/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:28:52 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/12 13:13:35 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	pyth(double a, double b)
{
	return (sqrt((a * a) + (b * b)));
}

/* --------------- Calcul du delta --------------------*/
void	ft_delta(t_point2d *v)
{
	double	delta_x;
	double	delta_y;
	double	step;

	delta_x = v->vx - v->x;
	delta_y = v->vy - v->y;
	if (fabs(delta_x) >= fabs(delta_y))
		step = fabs(delta_x);
	else
		step = fabs(delta_y);
	v->d_x = delta_x / step;
	v->d_y = delta_y / step;
}

/* --------------- Tan Opp Adj - Pythagore --------------------*/
double	ft_opp(double radian, double adj)
{
	return (adj * tan(radian));
}

double	ft_radian(double angle)
{
	return ((angle / 180) * PI);
}

void	vector_xy(t_game *game, t_img *img, t_cube *cube)
{
	double		opp;
	double		dist;
	double		angle;
	double		radian;
	double		step;
	t_point2d	p;

	(void) game;
	dist = 100;
	angle = 33;
	radian = ft_radian(angle);
	opp = ft_opp(radian, dist);
	p.x = cube->game->px_scr;
	p.y = cube->game->py_scr;
	p.vx = p.x - opp;
	p.vy = p.y - dist;
	step = pyth(dist, opp);
	while (step > 0)
	{
		// if (cube->map->maps[s_to_m(2, p.y, cube)][s_to_m(1, p.x, cube)] != 0)
		// 	break;
		img_pix_put(img, p.x, p.y, GREEN);
		p.x += p.d_x;
		p.y += p.d_y;
		step--;
	}
}

