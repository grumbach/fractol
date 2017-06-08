/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:44:31 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/08 23:13:43 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			julia(t_mlx *mlx, double y, double x)
{
	t_color	color;
	int		iteration;
	t_xy	base;
	t_xy	tmp;

	base.x = CLAMPX(mlx->view.base.x);
	base.y = CLAMPY(mlx->view.base.y);
	iteration = 0;
	x = CLAMPX(x) / mlx->view.zoom + mlx->view.pos.x;
	y = CLAMPY(y) / mlx->view.zoom + mlx->view.pos.y;
	while (x * x + y * y < mlx->view.radius && iteration < mlx->view.iterations)
	{
		tmp.x = x * x - y * y + base.x;
		tmp.y = x * y * 2 + base.y;
		x = tmp.x;
		y = tmp.y;
		++iteration;
	}
	color.bgr[2] = iteration * iteration * iteration;
	return (color.color);
}
