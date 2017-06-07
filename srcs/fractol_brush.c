/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_brush.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:10:06 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/07 16:07:51 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int				i;

	if (x >= WIN_W || y >= WIN_H || x < 0 || y < 0)
	{
		ft_printf("OUT OF BOUNDS x = %d, y = %d\n", x, y);
		return ;
	}
	i = mlx->linesize * y + x * (mlx->bpp / 8);
	mlx->data[i] = color & 0xff;
	mlx->data[++i] = color >> 8 & 0xff;
	mlx->data[++i] = color >> 16;
}

void		painter(t_mlx *mlx)
{
	int		plotx;
	int		ploty;
	static int	(*frac[NB_FRACTALS])(t_mlx*, double, double) = \
					{&julia, &mandelbrot};

	ploty = WIN_H - 1;
	while (ploty)
	{
		plotx = WIN_W - 1;
		while (plotx)
		{
			ft_printf("%d, %d\n", plotx, ploty);
			put_pixel(mlx, plotx, ploty, \
				frac[mlx->fractal](mlx, ploty, plotx));
			--plotx;
		}
		--ploty;
	}
}

void		cleaner(t_mlx *mlx)
{
	ft_bzero(mlx->data, mlx->linesize * (WIN_H - 1) * (mlx->bpp / 8));
}
