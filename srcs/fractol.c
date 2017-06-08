/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:25:12 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/08 23:47:10 by agrumbac         ###   ########.fr       */
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
	else if (err == 2)
		ft_putstr_fd("\nusage: ./fractol [julia mandelbrot ...]\n", 2);//more...
	exit(EXIT_FAILURE);
	return (0);
}

static int	fast_parse(int ac, char **av)
{
	if (ac == 2 && av)
	{
		if (ft_strequ(av[1], "julia"))
			return (JULIA);
		if (ft_strequ(av[1], "mandelbrot"))
			return (MANDELBROT);
	}
	return ((int)errors(2, 0));
}

int			main(int ac, char **av)
{
	t_mlx		mlx;

	ft_bzero(&mlx, sizeof(t_mlx));
	mlx.fractal = fast_parse(ac, av);
	mlx.mlx_ptr = mlx_init();
	mlx.view.pos.x = 0;
	mlx.view.pos.y = 0;
	mlx.view.zoom = DEFAULT_ZOOM;
	mlx.view.iterations = DEFAULT_ITER;
	mlx.view.radius = DEFAULT_RAD;
	if (!(mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_W, WIN_H, WIN_NAME)) ||
		!(mlx.img = mlx_new_image(mlx.mlx_ptr, IMG_W, IMG_H)) ||
		!(mlx.data = mlx_get_data_addr(mlx.img, &(mlx.bpp), &(mlx.linesize), \
			&(mlx.endian))))
		errors(1, 0);
	mlx_hook(mlx.win, 2, 3, keys, &mlx);
	mlx_hook(mlx.win, 6, 1 << 8, mouse, &mlx);
	mlx_mouse_hook(mlx.win, wheel, &mlx);
	painter(&mlx);
	mlx_loop(mlx.mlx_ptr);
	pthread_exit(NULL);
	return (EXIT_SUCCESS);
}
