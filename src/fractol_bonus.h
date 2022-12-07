/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:14:58 by tkong             #+#    #+#             */
/*   Updated: 2022/12/07 21:18:28 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# define HEIGHT			300
# define WIDTH			300
# define TRY_LIMIT		100
# define MAX_ABS		2.0
# define IT_MAX_INIT	50
# define IT_MAX_MAX		300
# define IT_MAX_MIN		1

# include "../ft/ft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>

enum e_color
{
	RED		= 0x00ff0000,
	GREEN	= 0x0000ff00,
	BLUE	= 0x000000ff,
	BLACK	= 0x00000000,
	WHITE	= 0x00ffffff,
};

enum e_keycode
{
	KEY_ESC		= 0x35,
	KEY_0		= 0x1D,
	KEY_MINUS	= 0x1B,
	KEY_PLUS	= 0x18,
};

enum e_mousecode
{
	LEFT_CLICK	= 0x01,
	RIGHT_CLICK	= 0x02,
	MID_CLICK	= 0x03,
	SCROLL_UP	= 0x04,
	SCROLL_DOWN	= 0x05,
};

enum e_event
{
	KEYDOWN		= 2,
	KEYUP		= 3,
	MOUSEDOWN	= 4,
	MOUSEUP		= 5,
	MOUSEMOVE	= 6,
	EXPOSE		= 12,
	DESTROY		= 17,
};

typedef struct s_cpx
{
	t_f64	re;
	t_f64	im;
}	t_cpx;

typedef struct s_pix
{
	t_i32	x;
	t_i32	y;
	t_i32	color;
}	t_pix;

typedef struct s_frac
{
	void	(*ftr)();
	t_i32	itpp[WIDTH * HEIGHT];
	t_i32	it_cur;
	t_i32	it_max;
	t_cpx	max;
	t_cpx	min;
	t_cpx	fact;
	t_cpx	z;
	t_cpx	c;
	t_cpx	k;
}	t_frac;

typedef struct s_dat
{
	void	*img;
	t_i8	*addr;
	t_i32	bpp;
	t_i32	llen;
	t_i32	endian;
}	t_dat;

typedef struct s_db
{
	t_i32	init_try;
	void	*mlx;
	void	*win;
	t_dat	dat;
	t_frac	frac;
	t_pix	pix;
}	t_db;

void	mlx_pixel_put2(t_dat *data, t_i32 x, t_i32 y, t_i32 color);
t_i32	mlx_get_color(t_i32 color, t_i32 which);
void	mlx_set_color(t_i32 *color, t_i32 to, t_i32 which);

t_cpx	make_cpx(t_f64 re, t_f64 im);

t_i32	execute(t_db *db);
void	render(t_db *db);

void	gen_color(t_db *db);

t_i32	quit(void);
t_i32	key_press(t_i32 code, t_db *db);
void	it_reset(t_db *db);
void	it_incre(t_db *db);
void	it_decre(t_db *db);
t_i32	mouse_down(t_i32 code, t_i32 x, t_i32 y, t_db *db);
void	zoom(t_i32 code, t_i32 x, t_i32 y, t_db *db);

void	mandelbrot(t_db *db);
void	julia(t_db *db);
void	mandelbar(t_db *db);

#endif
