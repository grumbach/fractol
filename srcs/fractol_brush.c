/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_brush.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:10:06 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/12 23:56:35 by agrumbac         ###   ########.fr       */
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

static void	*threadman(void *mlx)
{
	t_xy		plot;
	t_xy		start_end;
	pthread_t	s;
	static int	(*frac[NB_FRACTALS])(t_mlx*, double, double) = \
			{&julia, &mandelbrot, &bibrot, &tribrot, &quadbrot, &burningship, &dragon, &phoenix};//more ...

	start_end.x = 0;
	s = pthread_self();
	while (s != ((t_mlx*)mlx)->threads[start_end.x])
		start_end.x++;
	start_end.y = (start_end.x + 1) * IMG_W / NB_THREADS;
	start_end.x = start_end.x * IMG_W / NB_THREADS;
	plot.y = IMG_H - 1;
	while (plot.y)
	{
		plot.x = start_end.x;
		while (plot.x < start_end.y)
		{
			put_pixel(mlx, plot.x, plot.y, \
				frac[((t_mlx*)mlx)->fractal](mlx, plot.y, plot.x));
			++plot.x;
		}
		--plot.y;
	}
	pthread_exit(NULL);
}

void		painter(t_mlx *mlx)
{
	int			rc;
	int			i;

	i = 0;
	while (i < NB_THREADS)
	{
		if ((rc = pthread_create(&mlx->threads[i], NULL, threadman, mlx)))
			errors(0, 0);
		++i;
	}
	i = -1;
	while (++i < NB_THREADS)
		if (pthread_join(mlx->threads[i], NULL))
			errors(0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img, -5, -5);
}
