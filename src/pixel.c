#include "fractol.h"

static t_axs	ctoa(t_cpx cx);
static t_cpx	atoc(t_axs ax);

void	set_complex(t_db *db, t_cpx cx)
{
	db->dat.pix.cx = cx;
	db->dat.pix.ax = ctoa(db->dat.pix.cx);
}

void	set_axis(t_db *db, t_axs ax)
{
	db->dat.pix.ax = ax;
	db->dat.pix.cx = atoc(db->dat.pix.ax);
}

void	gen_color(t_db *db)
{
	t_f64	ratio;

	ratio = (t_f64) db->frac.it_cur / db->frac.it_max;
	mlx_set_color(&(db->dat.pix.color),
		(t_u8)(9 * (1 - ratio) * pow(ratio, 3) * 255), RED);
	mlx_set_color(&(db->dat.pix.color),
		(t_u8)(15 * pow((1 - ratio), 2) * pow(ratio, 2) * 255), GREEN);
	mlx_set_color(&(db->dat.pix.color),
		(t_u8)(8.5 * pow((1 - ratio), 3) * ratio * 255), BLUE);
}

static t_axs	ctoa(t_cpx cx)
{
	t_axs	tmp;

	cx.re += MAX_ABS;
	cx.im += MAX_ABS;
	tmp.x = cx.re / (pow(MAX_ABS, 2) / WIDTH);
	tmp.y = cx.im / (pow(MAX_ABS, 2) / HEIGHT);
	return (tmp);
}

static t_cpx	atoc(t_axs ax)
{
	t_cpx	tmp;

	tmp.re = -MAX_ABS;
	tmp.im = -MAX_ABS;
	tmp.re += pow(MAX_ABS, 2) / WIDTH * ax.x;
	tmp.im += pow(MAX_ABS, 2) / HEIGHT * ax.y;
	return (tmp);
}
