#include "fractol.h"

void	it_reset(t_db *db)
{
	if (db->frac.it_max != IT_MAX_INIT)
	{
		db->frac.it_max = IT_MAX_INIT;
		render(db);
	}
}

void	it_incre(t_db *db)
{
	if (db->frac.it_max < IT_MAX_MAX)
	{
		db->frac.it_max++;
		render(db);
	}
}

void	it_decre(t_db *db)
{
	if (db->frac.it_max > IT_MAX_MIN)
	{
		db->frac.it_max--;
		render(db);
	}
}
