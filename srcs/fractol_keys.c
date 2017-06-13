/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:12:51 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/13 19:35:48 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		fractal_change(t_mlx *mlx, const int keycode)
{
	if (keycode < 90)
		mlx->fractal = keycode - 83;
	else
		mlx->fractal = keycode - 84;
}

static void		position(t_mlx *mlx, const int keycode)
{
	if (keycode == 126)
		mlx->view.pos.y -= 0.1 / mlx->view.zoom;
	if (keycode == 125)
		mlx->view.pos.y += 0.1 / mlx->view.zoom;
	if (keycode == 123)
		mlx->view.pos.x -= 0.1 / mlx->view.zoom;
	if (keycode == 124)
		mlx->view.pos.x += 0.1 / mlx->view.zoom;
}

static void		iterations(t_mlx *mlx, const int keycode)
{
	if (!(keycode & 0x01))
		mlx->view.iterations += 10;
	else if (mlx->view.iterations)
		mlx->view.iterations -= 10;
}

static void		modeset(t_mlx *mlx, const int keycode)
{
	if (keycode == 51)
	{
		mlx->view.zoom = DEFAULT_ZOOM;
		mlx->view.iterations = DEFAULT_ITER;
		mlx->view.pos.x = 0;
		mlx->view.pos.y = 0;
	}
	else
		mlx->mouse_follow ^= 1;
}

int				keys(int keycode, void *param)
{
	ft_printf("keycode press = %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(((t_mlx *)param)->mlx_ptr, ((t_mlx *)param)->img);
		mlx_destroy_window(((t_mlx *)param)->mlx_ptr, ((t_mlx *)param)->win);
		exit(1);
	}
	else if (keycode == 123 || keycode == 125 || \
		 		keycode == 126 || keycode == 124)
		position(param, keycode);
	else if ((keycode >= 83 && keycode <= 89) || keycode == 91 || keycode == 92)
		fractal_change(param, keycode);
	else if (keycode == 78)
		unzoom(param, IMG_W / 2, IMG_H / 2);
	else if (keycode == 69)
		zoom(param, IMG_W / 2, IMG_H / 2);
	else if (keycode == 116 || keycode == 121)
		iterations(param, keycode);
	else if (keycode == 51 || keycode == 49)
		modeset(param, keycode);
	painter(param);
	return (0);
}
