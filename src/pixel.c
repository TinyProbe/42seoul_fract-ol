/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:49:10 by tkong             #+#    #+#             */
/*   Updated: 2022/12/07 15:49:22 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	gen_color(t_db *db)
{
	t_f64	ratio;

	ratio = (t_f64) db->frac.itpp[WIDTH * db->pix.y + db->pix.x]
		/ db->frac.it_max;
	mlx_set_color(&(db->pix.color),
		(t_u8)(9 * (1 - ratio) * pow(ratio, 3) * 255), RED);
	mlx_set_color(&(db->pix.color),
		(t_u8)(15 * pow((1 - ratio), 2) * pow(ratio, 2) * 255), GREEN);
	mlx_set_color(&(db->pix.color),
		(t_u8)(8.5 * pow((1 - ratio), 3) * ratio * 255), BLUE);
}
