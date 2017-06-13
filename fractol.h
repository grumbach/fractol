/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:26:28 by agrumbac          #+#    #+#             */
/*   Updated: 2017/06/13 22:06:17 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "libft.h"
#include "mlx.h"

# include <errno.h>
# include <math.h>

#include <pthread.h>

# define NB_THREADS	8

# define WIN_NAME	"fractol"
# define WIN_W		1024
# define WIN_H		632

# define IMG_W		(WIN_W + 10)
# define IMG_H		(WIN_H + 10)

# define CLAMPX(x)	((x / IMG_W) * 3.5 - 2.5)
# define CLAMPY(y)	((y / WIN_H) * 2 - 1)

typedef union		u_color
{
	int				color;
	char			bgr[3];
}					t_color;

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef struct		s_ri
{
	double			x;
	double			y;
}					t_ri;

typedef struct		s_view
{
	double			zoom;
	double			iterations;
	t_ri			base;
	t_ri			pos;
	int				colorset;
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
	int				mouse_follow;
	pthread_t		threads[NB_THREADS];
}					t_mlx;

# define NB_FRACTALS		9//more...

# define DEFAULT_ITER		50
# define DEFAULT_ZOOM		1

/*
** fractals
*/

int			julia(t_mlx *mlx, double y, double x);
int			mandelbrot(t_mlx *mlx, double y, double x);
int			bibrot(t_mlx *mlx, double y, double x);
int			tribrot(t_mlx *mlx, double y, double x);
int			quadbrot(t_mlx *mlx, double y, double x);
int			burningship(t_mlx *mlx, double y, double x);
int			dragon(t_mlx *mlx, double y, double x);
int			phoenix(t_mlx *mlx, double y, double x);
int			tricorn(t_mlx *mlx, double y, double x);

/*
** fractol
*/

void		painter(t_mlx *mlx);
void		put_pixel(t_mlx *mlx, int x, int y, int color);
long		errors(const int err, const char *name);

/*
** interract
*/

int			keys(int keycode, void *param);
int			mouse(int x, int y, void *param);
int			wheel(int button, const int x, const int y, void *param);
void		unzoom(t_mlx *mlx, const int x, const int y);
void		zoom(t_mlx *mlx, const int x, const int y);

#endif
