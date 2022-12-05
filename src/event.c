#include "fractol.h"

t_i32	key_press(t_i32 keycode, t_db *db)
{
	if (keycode == KEY_ESC)
		quit();
	else if (keycode == KEY_0)
		it_reset(db);
	else if (keycode == KEY_MINUS)
		it_decre(db);
	else if (keycode == KEY_EQUAL)
		it_incre(db);
	return (0);
}

t_i32	mouse_hook(t_i32 mousecode, t_i32 x, t_i32 y, t_db *db)
{
	if (mousecode == SCROLL_UP)
		scroll_up(x, y, db);
	else if (mousecode == SCROLL_DOWN)
		scroll_down(x, y, db);
	return (0);
}
