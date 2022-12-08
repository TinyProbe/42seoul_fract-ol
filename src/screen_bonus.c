/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:01:54 by tkong             #+#    #+#             */
/*   Updated: 2022/12/08 17:02:28 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	screen_up(t_db *db)
{
	db->frac.max.im += db->frac.fact.im * MOVE_UNIT;
	db->frac.min.im += db->frac.fact.im * MOVE_UNIT;
	ft_bzero(db->frac.itpp, sizeof(t_i32) * WIDTH * HEIGHT);
	render(db);
}

void	screen_down(t_db *db)
{
	db->frac.max.im -= db->frac.fact.im * MOVE_UNIT;
	db->frac.min.im -= db->frac.fact.im * MOVE_UNIT;
	ft_bzero(db->frac.itpp, sizeof(t_i32) * WIDTH * HEIGHT);
	render(db);
}

void	screen_left(t_db *db)
{
	db->frac.max.re -= db->frac.fact.im * MOVE_UNIT;
	db->frac.min.re -= db->frac.fact.im * MOVE_UNIT;
	ft_bzero(db->frac.itpp, sizeof(t_i32) * WIDTH * HEIGHT);
	render(db);
}

void	screen_right(t_db *db)
{
	db->frac.max.re += db->frac.fact.im * MOVE_UNIT;
	db->frac.min.re += db->frac.fact.im * MOVE_UNIT;
	ft_bzero(db->frac.itpp, sizeof(t_i32) * WIDTH * HEIGHT);
	render(db);
}
