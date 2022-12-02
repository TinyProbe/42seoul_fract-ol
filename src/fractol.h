#ifndef MAIN_H
# define MAIN_H

# define HEIGHT	500
# define WIDTH	500

# include "../ft/ft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>

enum e_fractol
{
	MANDELBROT	= 1,
	JULIA		= 2,
	MANDELBAR	= 3,
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

typedef struct s_complex
{
	t_f64	re;
	t_f64	im;
}	t_complex;

typedef struct s_pixel
{
	t_i32	x;
	t_i32	y;
}	t_pixel;

typedef struct s_frac
{
	t_i32	fractol;
	t_f64	max_re;
	t_f64	min_re;
	t_f64	max_im;
	t_f64	min_im;
	t_i32	max_iter;
}	t_frac;

typedef struct s_data
{
	void	*img;
	t_i8	*addr;
	t_i32	bpp;
	t_i32	llen;
	t_i32	endian;
}	t_data;

typedef struct s_ds
{
	void	*mlx;
	void	*win;
	t_data	dat;
	t_frac	frac;
}	t_ds;

void	mlx_pixel_put2(t_data *data, t_i32 x, t_i32 y, t_i32 color);
t_i32	mlx_get_red(t_i32 color);
t_i32	mlx_get_green(t_i32 color);
t_i32	mlx_get_blue(t_i32 color);
void	mlx_set_red(t_i32 *color, t_i32 r);
void	mlx_set_green(t_i32 *color, t_i32 g);
void	mlx_set_blue(t_i32 *color, t_i32 b);

t_ds	*store();
t_i32	execute();

t_i32	key_press(t_i32 keycode, t_ds *st);
t_i32	mouse_hook(t_i32 mousecode, t_i32 x, t_i32 y, t_ds *st);

t_i32	quit();
void	render();
void	scroll_up(t_i32 x, t_i32 y);
void	scroll_down(t_i32 x, t_i32 y);

#endif
