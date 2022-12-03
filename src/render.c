#include "fractol.h"

void	render()
{
	t_i32	x;
	t_i32	y;
	
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			set_axis((t_axs) { x, y });
			db()->frac.c = db()->dat.pix.cx;
			gen_color(db()->frac.ftr());
			mlx_pixel_put2(&(db()->dat), x, y, db()->dat.pix.color);
		}
	}
	mlx_put_image_to_window(db()->mlx, db()->win, db()->dat.img, 0, 0);
}
