/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:44:31 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/13 19:58:39 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			julia(t_mlx *mlx, double y, double x)
{
	t_color	color;
	int		iteration;
	t_ri	base;
	t_ri	tmp;

	base.x = CLAMPX(mlx->view.base.x);
	base.y = CLAMPY(mlx->view.base.y);
	iteration = 0;
	x = CLAMPX(x) / mlx->view.zoom + mlx->view.pos.x;
	y = CLAMPY(y) / mlx->view.zoom + mlx->view.pos.y;
	while (x * x + y * y < 4 && iteration < mlx->view.iterations)
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

int			burningship(t_mlx *mlx, double y, double x)
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
		tmp.x = fabs(x * x - y * y + base.x);
		tmp.y = fabs(x * y * 2 + base.y);
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

int			dragon(t_mlx *mlx, double y, double x)
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
		tmp.x = fabs(y * x * x * x - y * y + base.x);
		tmp.y = fabs(x * y * 2 + base.y);
		x = tmp.x;
		y = tmp.y;
		++iteration;
	}
	color.bgr[2] = iteration * iteration * iteration;
	return (color.color);
}

int			phoenix(t_mlx *mlx, double y, double x)
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
	while (x * x + y * y < 31.415926536 && iteration < 100)
	{
		tmp.x = sin(x) * cosh(y) + base.x;
		tmp.y = cos(x) * sinh(y) + base.y;
		x = tmp.x;
		y = tmp.y;
		++iteration;
	}
	color.bgr[2] = iteration * iteration * iteration;
	return (color.color);
}

int			tricorn(t_mlx *mlx, double y, double x)
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
		tmp.y = -1 * (x * y * 2) + base.y;
		x = tmp.x;
		y = tmp.y;
		++iteration;
	}
	color.bgr[2] = iteration * iteration * iteration;
	return (color.color);
}
