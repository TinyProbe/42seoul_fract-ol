#include "fractol.h"

static void		*which_fractol(t_i8 *av, t_db *db);
static t_i32	error(void);
static void		manual(void);

t_i32	main(t_i32 ac, t_i8 **av)
{
	t_db	db;

	ft_bzero(&db, sizeof(t_db));
	if (ac == 2 && which_fractol(av[1], &db))
		if (execute(&db))
			error();
	manual();
	exit(0);
}

static void	*which_fractol(t_i8 *av, t_db *db)
{
	if (ft_strcmp(av, "1") == EQUAL
		|| ft_strcmp(av, "mandelbrot") == EQUAL)
		db->frac.ftr = mandelbrot;
	else if (ft_strcmp(av, "2") == EQUAL
		|| ft_strcmp(av, "julia") == EQUAL)
		db->frac.ftr = julia;
	else if (ft_strcmp(av, "3") == EQUAL
		|| ft_strcmp(av, "mandelbar") == EQUAL)
		db->frac.ftr = mandelbar;
	return (db->frac.ftr);
}

static t_i32	error(void)
{
	perror("Unknown error occurred.");
	exit(-1);
}

static void	manual(void)
{
	printf("# Usage:						\n");
	printf("	$ ./fractal [NUM or NAME]	\n");
	printf("								\n");
	printf("# Available Fractal List:		\n");
	printf("	1. mandelbrot				\n");
	printf("	2. julia					\n");
	printf("	3. mandelbar				\n");
	printf("								\n");
}
