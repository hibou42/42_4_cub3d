/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:28:52 by nrossel           #+#    #+#             */
/*   Updated: 2023/10/12 13:51:53 by nrossel          ###   ########.fr       */
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
