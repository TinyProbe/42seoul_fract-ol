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
	// generate color from iteration.
	// and set pix.color
}

static t_axs	ctoa(t_cpx cx)
{
	t_axs	tmp;
	
	cx.re += 2.0;
	cx.im += 2.0;
	tmp.x = cx.re / (4.0 / WIDTH);
	tmp.y = cx.im / (4.0 / HEIGHT);
	return (tmp);
}

static t_cpx	atoc(t_axs ax)
{
	t_cpx	tmp;
	
	tmp.re = -2.0;
	tmp.im = -2.0;
	tmp.re += 4.0 / WIDTH * ax.x;
	tmp.im += 4.0 / HEIGHT * ax.y;
	return (tmp);
}
