/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_brush.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:10:06 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/08 23:56:59 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int			i;

	if (x >= IMG_W || y >= IMG_H || x < 0 || y < 0)
	{
		ft_printf("OUT OF BOUNDS x = %d, y = %d\n", x, y);
		return ;
	}
	i = mlx->linesize * y + x * (mlx->bpp / 8);
	mlx->data[i] = color & 0xff;
	mlx->data[++i] = color >> 8 & 0xff;
	mlx->data[++i] = color >> 16;
}

static void	*threadman(void *mlxx)
{
	t_mlx		*mlx;
	int			plotx;
	int			ploty;
	static int	(*frac[NB_FRACTALS])(t_mlx*, double, double) = \
					{&julia, &mandelbrot};

	mlx = mlxx;
	ploty = IMG_H - 1;
	while (ploty)
	{
		plotx = mlx->plotstart;
		while (plotx < mlx->plotend)
		{
			put_pixel(mlx, plotx, ploty, \
				frac[mlx->fractal](mlx, ploty, plotx));
			++plotx;
		}
		--ploty;
	}
	pthread_exit(NULL);
}

void		painter(t_mlx *mlx)
{
	pthread_t	threads[NB_THREADS];
	int			rc;
	int			i;

	i = 0;
	while (i < NB_THREADS)
	{
		mlx->plotstart = i * IMG_W / NB_THREADS;
		mlx->plotend = (i + 1) * IMG_W / NB_THREADS;
		if ((rc = pthread_create(&threads[i], NULL, threadman, mlx)))
			errors(0, 0);
		++i;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img, -5, -5);
}

void		cleaner(t_mlx *mlx)
{
	ft_bzero(mlx->data, mlx->linesize * (IMG_H - 1) * (mlx->bpp / 8));
}
