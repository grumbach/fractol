/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:44:52 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/13 23:15:14 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mandelbrot(t_mlx *mlx, double y, double x)
{
	t_color	color;
	int		iteration;
	t_ri	base;
	t_ri	tmp;

	base.x = CLAMPX(x) / mlx->view.zoom + mlx->view.pos.x;
	base.y = CLAMPY(y) / mlx->view.zoom + mlx->view.pos.y;
	iteration = 0;
	x = 0;
	y = 0;
	while (x * x + y * y < 4 && iteration < mlx->view.iterations)
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

int			bibrot(t_mlx *mlx, double y, double x)
{
	t_color	color;
	int		iteration;
	t_ri	base;
	t_ri	tmp;

	base.x = CLAMPX(x) / mlx->view.zoom + mlx->view.pos.x;
	base.y = CLAMPY(y) / mlx->view.zoom + mlx->view.pos.y;
	iteration = 0;
	x = 0;
	y = 0;
	while (x * x + y * y < 8 && iteration < mlx->view.iterations)
	{
		tmp.x = x * x * x - 3 * x * y * y + base.x;
		tmp.y = 3 * x * x * y - y * y * y + base.y;
		x = tmp.x;
		y = tmp.y;
		++iteration;
	}
	color.bgr[2] = iteration * iteration * iteration;
	return (color.color);
}

int			tribrot(t_mlx *mlx, double y, double x)
{
	t_color	color;
	int		iteration;
	t_ri	base;
	t_ri	tmp;

	base.x = CLAMPX(x) / mlx->view.zoom + mlx->view.pos.x;
	base.y = CLAMPY(y) / mlx->view.zoom + mlx->view.pos.y;
	iteration = 0;
	x = 0;
	y = 0;
	while (x * x + y * y < 16 && iteration < mlx->view.iterations)
	{
		tmp.x = x * x * x * x + y * y * y * y - 6 * x * x * y * y + base.x;
		tmp.y = (4 * x * y) * (x * x - y * y) + base.y;
		x = tmp.x;
		y = tmp.y;
		++iteration;
	}
	color.bgr[2] = iteration * iteration * iteration;
	return (color.color);
}

int			quadbrot(t_mlx *mlx, double y, double x)
{
	t_color	color;
	int		iteration;
	t_ri	base;
	t_ri	tmp;

	base.x = CLAMPX(x) / mlx->view.zoom + mlx->view.pos.x;
	base.y = CLAMPY(y) / mlx->view.zoom + mlx->view.pos.y;
	iteration = 0;
	x = 0;
	y = 0;
	while (x * x + y * y < 32 && iteration < mlx->view.iterations)
	{
		tmp.x = x * x * x * x * x - 10 * x * x * x * y * y + \
			5 * x * y * y * y * y + base.x;
		tmp.y = 5 * x * x * x * x * y - 10 * x * x * y * y * \
			y + y * y * y * y * y + base.y;
		x = tmp.x;
		y = tmp.y;
		++iteration;
	}
	color.bgr[2] = iteration * iteration * iteration;
	return (color.color);
}
