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
	mlx_loop(store()->mlx);
	return (0);
}

static t_i32	initialize()
{
	t_i32	try;
	
	try = 0;
	while (store()->mlx == NULL && try++ < 100)
		store()->mlx = mlx_init();
	while (store()->win == NULL && try++ < 100)
		store()->win = mlx_new_window(store()->mlx, WIDTH, HEIGHT, "APP");
	while (store()->dat.img == NULL && try++ < 100)
		store()->dat.img = mlx_new_image(store()->mlx, WIDTH, HEIGHT);
	while (store()->dat.addr == NULL && try++ < 100)
		store()->dat.addr = mlx_get_data_addr(
			store()->dat.img,
			&(store()->dat.bpp),
			&(store()->dat.llen),
			&(store()->dat.endian));
	if (try > 100)
		return (-1);
	return (0);
}

static void	regist_hook()
{
	mlx_hook(store()->win, DESTROY, 0, quit, NULL);
	mlx_hook(store()->win, KEYDOWN, 0, key_press, NULL);
	mlx_mouse_hook(store()->win, mouse_hook, NULL);
}

static void	init_fractol()
{
	store()->frac.min_re = -2.0f;
	store()->frac.max_re = 2.0f;
	store()->frac.min_im = -2.0f;
	store()->frac.max_im = 2.0f;
	store()->frac.max_iter = 50;
}
