#include "fractol.h"

t_i32	mandelbar()
{
	db()->frac.z = (t_cpx) { db()->frac.c.re, db()->frac.c.im };
	db()->frac.it_cur = -1;
	while (pow(db()->frac.z.re, 2) + pow(db()->frac.z.im, 2)
			<= pow(MAX_ABS, 2) && ++(db()->frac.it_cur) < db()->frac.it_max)
	{
		db()->frac.z.re =
			pow(db()->frac.z.re, 2) - pow(db()->frac.z.im, 2)
			+ db()->frac.c.re;
		db()->frac.z.im =
			-2 * db()->frac.z.re * db()->frac.z.im
			+ db()->frac.c.im;
	}
	return (db()->frac.it_cur);
}
