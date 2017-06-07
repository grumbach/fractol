/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:44:52 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/07 15:56:38 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// For each pixel (Px, Py) on the screen, do:
// {
//   x0 = scaled x coordinate of pixel
//		(scaled to lie in the Mandelbrot X scale (-2.5, 1))
//   y0 = scaled y coordinate of pixel
// 		(scaled to lie in the Mandelbrot Y scale (-1, 1))
//   x = 0.0
//   y = 0.0
//   iteration = 0
//   max_iteration = 1000
//   while (x*x + y*y < 2*2  AND  iteration < max_iteration) {
//     xtemp = x*x - y*y + x0
//     y = 2*x*y + y0
//     x = xtemp
//     iteration = iteration + 1
//   }
//   color = palette[iteration]
//   plot(Px, Py, color)
// }

int			mandelbrot(t_mlx *mlx, double y, double x)
{
	t_color	color;
	int		iteration;
	t_xy	base;

	base.x = ((y / WIN_W) * 3.5) - 2.5;
	base.y = ((y / WIN_H) * 2) - 1;
	iteration = 0;
	while (x * x + y * y < 4 && iteration < mlx->view.iterations)
	{
		x = x * x - y * y + base.x;
		y = x * y * 2 + base.y;
		++iteration;
	}
	color.b = iteration;
	color.g = iteration;
	return (color.color);
}
