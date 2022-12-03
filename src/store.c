#include "fractol.h"

t_db	*db()
{
	static t_db	db;
	
	return (&db);
}
