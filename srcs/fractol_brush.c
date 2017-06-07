/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_brush.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:10:06 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/07 14:54:23 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int				i;

	if (x >= WIN_W || y >= WIN_H || x < 0 || y < 0)
	{
		ft_printf("x = %d, y = %d\n", x, y);
		return ;
	}
	i = mlx->linesize * y + x * (mlx->bpp / 8);
	mlx->data[i] = color & 0xff;
	mlx->data[++i] = color >> 8 & 0xff;
	mlx->data[++i] = color >> 16;
}

void		painter(t_mlx *mlx)
{
	if (mlx->fractal == JULIA)
		julia(mlx);
	else if (mlx->fractal == MENDEL)
		mendel(mlx);
}

void		cleaner(t_mlx *mlx)
{
	ft_bzero(mlx->data, mlx->linesize * (WIN_H - 1) * (mlx->bpp / 8));
}
