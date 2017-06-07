/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:44:52 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/07 16:59:01 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mandelbrot(t_mlx *mlx, double y, double x)
{
	t_color	color;
	int		iteration;
	t_xy	base;
	double	tmpx;

	base.x = (x / IMG_W) * 3.5 - 2.5;
	base.y = (y / IMG_H) * 2 - 1;
	iteration = 0;
	x = 0;
	y = 0;
	while (x * x + y * y < 4 && iteration < mlx->view.iterations)
	{
		tmpx = x * x - y * y + base.x;
		y = x * y * 2 + base.y;
		x = tmpx;
		++iteration;
	}
	color.rgba[2] = iteration * iteration * iteration;
	return (color.color);
}
