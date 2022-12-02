#include "fractol.h"

void	mlx_pixel_put2(t_data *data, t_i32 x, t_i32 y, t_i32 color)
{
	*(t_u32 *) (data->addr + (y * data->llen +
		x * (data->bpp / 8))) = color;
}

t_i32	mlx_get_red(t_i32 color)
{
	return ((color & (0xff << 16)) >> 16);
}

t_i32	mlx_get_green(t_i32 color)
{
	return ((color & (0xff << 8)) >> 8);
}

t_i32	mlx_get_blue(t_i32 color)
{
	return ((color & (0xff << 0)) >> 0);
}

void	mlx_set_red(t_i32 *color, t_i32 r)
{
	*color &= ((0xff << 24) | (0xff << 8) | (0xff << 0));
	*color |= (r << 16);
}

void	mlx_set_green(t_i32 *color, t_i32 g)
{
	*color &= ((0xff << 24) | (0xff << 16) | (0xff << 0));
	*color |= (g << 8);
}

void	mlx_set_blue(t_i32 *color, t_i32 b)
{
	*color &= ((0xff << 24) | (0xff << 16) | (0xff << 8));
	*color |= (b << 0);
}
