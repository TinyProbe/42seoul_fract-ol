/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:15:29 by tkong             #+#    #+#             */
/*   Updated: 2022/12/07 16:16:58 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cpx	make_cpx(t_f64 re, t_f64 im)
{
	static t_cpx	tmp;

	tmp.re = re;
	tmp.im = im;
	return (tmp);
}
