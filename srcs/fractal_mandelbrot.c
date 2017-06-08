/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:44:52 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/08 23:13:50 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mandelbrot(t_mlx *mlx, double y, double x)
{
	t_color	color;
	int		iteration;
	t_xy	base;
	t_xy	tmp;

	base.x = CLAMPX(x) / mlx->view.zoom + mlx->view.pos.x;
	base.y = CLAMPY(y) / mlx->view.zoom + mlx->view.pos.y;
	iteration = 0;
	x = 0;
	y = 0;
	while (x * x + y * y < mlx->view.radius && iteration < mlx->view.iterations)
	{
		tmp.x = x * x - y * y + base.x;
		tmp.y = x * y * 2 + base.y;
		if (tmp.x == x && tmp.y == y)
		{
			iteration = mlx->view.iterations;
			break ;
		}
		x = tmp.x;
		y = tmp.y;
		++iteration;
	}
	color.bgr[2] = iteration * iteration * iteration;
	return (color.color);
}
