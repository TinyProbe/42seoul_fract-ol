#include "fractol.h"

t_i32	mandelbar(t_frac *frac)
{
	t_i32		iter;
	t_complex	z;

	iter = 0;
	z = make_complex(frac->c.re, frac->c.im);
	while (pow(z.re, 2) + pow(z.im, 2) <= 4 && iter < frac->max_iter)
	{
		z = make_complex(
			pow(z.re, 2) - pow(z.im, 2) + frac->c.re,
			-2.0 * z.re * z.im + frac->c.im);
		iter++;
	}
	return (iter);
}
