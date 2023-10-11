/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:28:52 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/11 17:49:21 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	pyth(double a, double b)
{
	return (sqrt((a * a) + (b * b)));
}

/* --------------- Calcul du delta --------------------*/
double	ft_delta(t_point2d *v)
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
	return (step);
}

/* --------------- Tan Opp Adj - Pythagore --------------------*/
double	tan_opp_adj(int define, double angle_a, double adj, double opp)
{
	if (define == 1) // -->> cherche Tangente
		return (opp / adj);
	else if (define == 2) // -->> cherche opposé
		return (adj * atan(angle_a));
	else if (define == 3) // -->> cherche adjacent
		return (opp / atan(angle_a));
	return (0);
}

void	vector_xy(t_game *game, t_img *img)
{
	double		opp;
	double		dist;
	double		angle;
	int			step;
	t_point2d	p;

	dist = 20;
	angle = 30;
	opp = tan_opp_adj(2, angle, dist, 0);
	p.x = game->p_x;
	p.y = game->p_y;
	p.vx = game->p_x - opp;
	p.vy = game->p_y + dist;
	step = ft_delta(&p);
	printf("opp = %f\ndist = %f\nangle = %f\nstep = %d\n", opp, dist, angle, step);
	printf("--------------------------------------------------\n");
	printf("p.x = %f - p.y = %f\n", p.x, p.y);
	printf("p.vx = %f - p.vy = %f\n", p.vx, p.vy);
	printf("p.d_x = %f - p.d_y = %f\n", p.d_x, p.d_y);
	while (step > 0)
	{
		img_pix_put(img, p.x, p.y, GREEN);
		p.x += p.d_x;
		p.y += p.d_y;
		step--;
	}
}
