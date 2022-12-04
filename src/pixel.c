#include "fractol.h"

static t_axs	ctoa(t_cpx cx);
static t_cpx	atoc(t_axs ax);

void	set_complex(t_cpx cx)
{
	db()->dat.pix.cx.re = cx.re;
	db()->dat.pix.cx.im = cx.im;
	db()->dat.pix.ax = ctoa(db()->dat.pix.cx);
}

void	set_axis(t_axs ax)
{
	db()->dat.pix.ax.x = ax.x;
	db()->dat.pix.ax.y = ax.y;
	db()->dat.pix.cx = atoc(db()->dat.pix.ax);
}

void	gen_color(t_i32 it)
{
	t_f64 unit;

	unit = (t_f64) 0xff / db()->frac.it_max;
	mlx_set_color(&(db()->dat.pix.color), 0xff - it * unit, RED);
	mlx_set_color(&(db()->dat.pix.color), 0xff - it * unit, GREEN);
	mlx_set_color(&(db()->dat.pix.color), 0xff - it * unit, BLUE);
}

static t_axs	ctoa(t_cpx cx)
{
	t_axs	tmp;
	
	cx.re += MAX_ABS;
	cx.im += MAX_ABS;
	tmp.x = cx.re / (pow(MAX_ABS, 2) / WIDTH);
	tmp.y = cx.im / (pow(MAX_ABS, 2) / HEIGHT);
	return (tmp);
}

static t_cpx	atoc(t_axs ax)
{
	t_cpx	tmp;
	
	tmp.re = db()->frac.min_re;
	tmp.im = db()->frac.min_im;
	tmp.re += pow(MAX_ABS, 2) / WIDTH * ax.x;
	tmp.im += pow(MAX_ABS, 2) / HEIGHT * ax.y;
	return (tmp);
}
