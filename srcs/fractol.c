/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:25:12 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/07 14:51:18 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long		errors(const int err, const char *name)
{
	ft_putstr_fd("fractol: ", 2);
	if (name)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(" ", 2);
	}
	if (err == 0)
		ft_putendl_fd(strerror(errno), 2);
	else if (err == 1)
		ft_putstr_fd("mlx failure\n", 2);
	exit(EXIT_FAILURE);
	return (0);
}

int			main(void)
{
	t_mlx		mlx;

	ft_bzero(&mlx, sizeof(t_mlx));
	mlx.fractal = 1;
	mlx.mlx_ptr = mlx_init();
	mlx.view.zoom = 10;
	mlx.view.pos.x = 100;
	mlx.view.pos.y = 100;
	if (!(mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_W, WIN_H, WIN_NAME)) ||
		!(mlx.img = mlx_new_image(mlx.mlx_ptr, WIN_W, WIN_H)) ||
		!(mlx.data = mlx_get_data_addr(mlx.img, &(mlx.bpp), &(mlx.linesize), \
			&(mlx.endian))))
		errors(1, 0);
	mlx_hook(mlx.win, 2, 3, keys, &mlx);
	mlx_mouse_hook(mlx.win, mouse, &mlx);
	painter(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}
