#include "fractol.h"

static t_f64	interpolate(t_f64 start, t_f64 end, t_f64 interp);

void	zoom(t_i32 button, t_i32 x, t_i32 y, t_db *db)
{
	t_cpx	mouse;
	t_f64	interp;

	mouse = make_cpx(
			(t_f64) x / (WIDTH / (db->frac.max.re
					- db->frac.min.re)) + db->frac.min.re,
			(t_f64) y / (HEIGHT / (db->frac.max.im
					- db->frac.min.im)) * -1 + db->frac.max.im);
	if (button == SCROLL_UP)
		interp = 1.0 / 0.8;
	else
		interp = 1.0 / 1.2;
	db->frac.min.re = interpolate(mouse.re, db->frac.min.re, interp);
	db->frac.min.im = interpolate(mouse.im, db->frac.min.im, interp);
	db->frac.max.re = interpolate(mouse.re, db->frac.max.re, interp);
	db->frac.max.im = interpolate(mouse.im, db->frac.max.im, interp);
	ft_bzero(db->frac.itpp, sizeof(t_i32) * WIDTH * HEIGHT);
	render(db);
}

static t_f64	interpolate(t_f64 start, t_f64 end, t_f64 interp)
{
	return (start + ((end - start) * interp));
}
