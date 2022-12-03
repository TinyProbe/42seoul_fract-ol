#include "fractol.h"

t_i32	key_press(t_i32 keycode, t_db *st)
{
	(void) st;
	if (keycode == KEY_ESC)
		quit();
	return (0);
}

t_i32	mouse_hook(t_i32 mousecode, t_i32 x, t_i32 y, t_db *st)
{
	(void) st;
	if (mousecode == SCROLL_UP)
		scroll_up(x, y);
	else if (mousecode == SCROLL_DOWN)
		scroll_down(x, y);
	return (0);
}
