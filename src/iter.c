#include "fractol.h"

void	it_reset(t_db *db)
{
	if (db->frac.it_max != IT_MAX_INIT)
	{
		db->frac.it_max = IT_MAX_INIT;
		printf("it_max : %d\n", db->frac.it_max);
		ft_bzero(db->frac.itpp, sizeof(t_i32) * WIDTH * HEIGHT);
		db->frac.max = make_cpx(MAX_ABS, MAX_ABS);
		db->frac.min = make_cpx(-MAX_ABS, -MAX_ABS);
		render(db);
	}
}

void	it_incre(t_db *db)
{
	if (db->frac.it_max < IT_MAX_MAX)
	{
		printf("it_max : %d\n", ++(db->frac.it_max));
		render(db);
	}
}

void	it_decre(t_db *db)
{
	if (db->frac.it_max > IT_MAX_MIN)
	{
		printf("it_max : %d\n", --(db->frac.it_max));
		render(db);
	}
}
