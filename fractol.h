/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:26:28 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/07 14:49:34 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "libft.h"
#include "mlx.h"

# include <errno.h>
# include <math.h>

#include <pthread.h>

# define WIN_NAME	"fractol"
# define WIN_W		1024
# define WIN_H		632

typedef union		u_color
{
	int				color;
	char			r;
	char			g;
	char			b;
}					t_color;//

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef struct		s_view
{
	int				zoom;
	t_xy			pos;
}					t_view;

typedef struct		s_mlx
{
	t_view			view;
	void			*mlx_ptr;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				linesize;
	int				endian;
	int				fractal;
}					t_mlx;

# define JULIA	1
# define MENDEL	2
# define SQUARE	3
# define CIRCLE	4

/*
** fractals
*/

void		julia(t_mlx *mlx);
void		mendel(t_mlx *mlx);

/*
** fractol
*/

void		painter(t_mlx *mlx);
void		cleaner(t_mlx *mlx);
void		put_pixel(t_mlx *mlx, int x, int y, int color);
long		errors(const int err, const char *name);

/*
** interract
*/

int			keys(int keycode, void *param);
int			mouse(int button, int x, int y, void *param);
void		unzoom(t_mlx *mlx);
void		zoom(t_mlx *mlx);

#endif
