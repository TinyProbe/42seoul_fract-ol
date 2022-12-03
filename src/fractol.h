#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT		500
# define WIDTH		500
# define MAX_ABS	2.0

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

typedef struct s_axs
{
	t_i32	x;
	t_i32	y;
}	t_axs;

typedef struct s_pix
{
	t_cpx	cx;
	t_axs	ax;
	t_i32	color;
}	t_pix;

typedef struct s_frac
{
	t_i32	(*ftr)();
	t_f64	max_re;
	t_f64	min_re;
	t_f64	max_im;
	t_f64	min_im;
	t_i32	it_cur;
	t_i32	it_max;
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
	t_pix	pix;
}	t_dat;

typedef struct s_db
{
	void	*mlx;
	void	*win;
	t_dat	dat;
	t_frac	frac;
}	t_db;

void	mlx_pixel_put2(t_dat *data, t_i32 x, t_i32 y, t_i32 color);
t_i32	mlx_get_color(t_i32 color, t_i32 which);
void	mlx_set_color(t_i32 *color, t_i32 to, t_i32 which);

t_db	*db();

t_i32	execute();
void	render();

void	set_complex(t_cpx cx);
void	set_axis(t_axs ax);
void	gen_color(t_i32 it);

t_i32	quit();
t_i32	key_press(t_i32 keycode, t_db *st);
t_i32	mouse_hook(t_i32 mousecode, t_i32 x, t_i32 y, t_db *st);
void	scroll_up(t_i32 x, t_i32 y);
void	scroll_down(t_i32 x, t_i32 y);

t_i32	mandelbrot();
t_i32	julia();
t_i32	mandelbar();

#endif
