#include "fractol.h"

static t_i32	initialize();
static void		regist_hook();
static void		init_fractol();

t_i32	execute()
{
	if (initialize())
		return (-1);
	regist_hook();
	init_fractol();
	render();
	mlx_loop(db()->mlx);
	return (0);
}

static t_i32	initialize()
{
	t_i32	try;
	
	try = 0;
	while (db()->mlx == NULL && try++ < 100)
		db()->mlx = mlx_init();
	while (db()->win == NULL && try++ < 100)
		db()->win = mlx_new_window(db()->mlx, WIDTH, HEIGHT, "Fractal");
	while (db()->dat.img == NULL && try++ < 100)
		db()->dat.img = mlx_new_image(db()->mlx, WIDTH, HEIGHT);
	while (db()->dat.addr == NULL && try++ < 100)
		db()->dat.addr = mlx_get_data_addr(
			db()->dat.img,
			&(db()->dat.bpp),
			&(db()->dat.llen),
			&(db()->dat.endian));
	if (try > 100)
		return (-1);
	return (0);
}

static void	regist_hook()
{
	mlx_hook(db()->win, DESTROY, 0, quit, NULL);
	mlx_hook(db()->win, KEYDOWN, 0, key_press, NULL);
	mlx_mouse_hook(db()->win, mouse_hook, NULL);
}

static void	init_fractol()
{
	db()->frac.min_re = -2.0f;
	db()->frac.max_re = 2.0f;
	db()->frac.min_im = -2.0f;
	db()->frac.max_im = 2.0f;
	db()->frac.it_max = IT_MAX;
}
