#include "fractol.h"

void	it_reset()
{
	if (db()->frac.it_max != IT_MAX)
	{
		db()->frac.it_max = IT_MAX;
		render();
	}
}

void	it_incre()
{
	if (db()->frac.it_max < IT_MAX_MAX)
	{
		db()->frac.it_max++;
		render();
	}
}

void	it_decre()
{
	if (db()->frac.it_max > IT_MAX_MIN)
	{
		db()->frac.it_max--;
		render();
	}
}
