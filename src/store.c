#include "fractol.h"

t_ds	*store()
{
	static t_ds	st;
	
	return (&st);
}
