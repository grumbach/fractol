/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:13:54 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/08 23:58:43 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom(t_mlx *mlx)
{
	mlx->view.zoom <<= 1;
}

void		unzoom(t_mlx *mlx)
{
	if (mlx->view.zoom > 1)
		mlx->view.zoom >>= 1;
}

int			wheel(int button, int x, int y, void *param)
{
	cleaner(param);
	ft_printf("mouse [x%d][y%d]: %d\n", x, y, button);
	if (button == 4)
		zoom(param);
	else if (button == 5)
		unzoom(param);
	painter(param);
	return (0);
}

int			mouse(int x, int y, void *param)
{
	if (!((t_mlx*)param)->fractal)
	{
		cleaner(param);
		((t_mlx*)param)->view.base.x = x;
		((t_mlx*)param)->view.base.y = y;
		painter(param);
	}
	return (0);
}
