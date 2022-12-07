/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:15:04 by tkong             #+#    #+#             */
/*   Updated: 2022/12/07 16:16:58 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_db *db)
{
	db->frac.z = db->frac.c;
	db->frac.it_cur = -1;
	while (++(db->frac.it_cur) < db->frac.it_max
		&& pow(db->frac.z.re, 2) + pow(db->frac.z.im, 2) <= pow(MAX_ABS, 2))
	{
		db->frac.z = make_cpx(
				pow(db->frac.z.re, 2) - pow(db->frac.z.im, 2) + db->frac.k.re,
				2 * db->frac.z.re * db->frac.z.im + db->frac.k.im);
	}
}
