#include "fractol.h"

t_cpx	make_cpx(t_f64 re, t_f64 im)
{
	static t_cpx	tmp;

	tmp.re = re;
	tmp.im = im;
	return (tmp);
}
