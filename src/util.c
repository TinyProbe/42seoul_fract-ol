#include "fractol.h"

t_cpx	make_cpx(t_f64 re, t_f64 im)
{
	static t_cpx	tmp;

	tmp.re = re;
	tmp.im = im;
	return (tmp);
}

t_axs	make_axs(t_i32 x, t_i32 y)
{
	static t_axs	tmp;

	tmp.x = x;
	tmp.y = y;
	return (tmp);
}
