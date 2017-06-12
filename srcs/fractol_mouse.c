/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:13:54 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/12 22:11:54 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom(t_mlx *mlx, const int x, const int y)
{
	mlx->view.pos.x += (x - IMG_W / 2) / (double)IMG_W / mlx->view.zoom;
	mlx->view.pos.y += (y - IMG_H / 2) / (double)IMG_H / mlx->view.zoom;
	mlx->view.zoom *= 1.15;
}

void		unzoom(t_mlx *mlx, const int x, const int y)
{
	if (mlx->view.zoom > 1)
	{
		mlx->view.pos.x -= (x - IMG_W / 2) / (double)IMG_W / mlx->view.zoom;
		mlx->view.pos.y -= (y - IMG_H / 2) / (double)IMG_H / mlx->view.zoom;
		mlx->view.zoom /= 1.15;
	}
}

int			wheel(int button, const int x, const int y, void *param)
{
	ft_printf("mouse [x%d][y%d]: %d\n", x, y, button);
	if (button == 4)
		zoom(param, x, y);
	else if (button == 5)
		unzoom(param, x, y);
	painter(param);
	return (0);
}

int			mouse(const int x, const int y, void *param)
{
	if (!((t_mlx*)param)->fractal && ((t_mlx*)param)->mouse_follow)
	{
		((t_mlx*)param)->view.base.x = x;
		((t_mlx*)param)->view.base.y = y;
		painter(param);
	}
	return (0);
}
