#include "fractol.h"

void	mandelbar(t_db *db)
{
	db->frac.z = db->frac.c;
	db->frac.it_cur = -1;
	while (++(db->frac.it_cur) < db->frac.it_max
		&& pow(db->frac.z.re, 2) + pow(db->frac.z.im, 2) <= pow(MAX_ABS, 2))
	{
		db->frac.z = make_cpx(
				pow(db->frac.z.re, 2) - pow(db->frac.z.im, 2) + db->frac.c.re,
				-2 * db->frac.z.re * db->frac.z.im + db->frac.c.im);
	}
}
