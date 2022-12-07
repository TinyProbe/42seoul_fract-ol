/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:48:59 by tkong             #+#    #+#             */
/*   Updated: 2022/12/07 15:49:22 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_i32	mouse_down(t_i32 code, t_i32 x, t_i32 y, t_db *db)
{
	if (code == SCROLL_UP || code == SCROLL_DOWN)
		zoom(code, x, y, db);
	return (0);
}
