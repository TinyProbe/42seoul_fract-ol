NAME		= fractol

CC			= gcc
FLAGS		= -Wall -Werror -Wextra -O3
LIB			= -lmlx -lm -lft				\
			  -L$(LIBFT_DIR) -L$(MLX_DIR)	\
			  -framework OpenGL -framework AppKit
INC			= -I$(HDR_DIR) -I$(LIBFT_HDR) -I$(MLX_HDR)

LIBFT_DIR	= ./libft/
LIBFT_HDR	= $(LIBFT_DIR)inc/
LIBFT		= $(LIBFT_DIR)libft.a

MLX_DIR		= ./mlx_mac/
MLX_HDR		= $(MLX_DIR)
MLX			= $(MLX_DIR)libmlx.a

HDR_DIR		= ./inc/
HDR_LST		= fractol.h			\
			  color.h			\
			  key_macos.h		\
			  error_message.h	\
HDR			= $(addprefix $(HDR_DIR), $(HDR_LST))

SRC_DIR		= ./src/
SRC_LST		= fractol.c								\
			  init.c								\
			  draw.c								\
			  color.c								\
			  print.c								\
			  utils.c								\
			  controls_keyboard.c					\
			  controls_mouse.c						\
			  controls_utils.c						\
			  fractal_mandelbrot.c					\
			  fractal_julia.c						\
			  fractal_burning_ship.c				\
			  fractal_mandelbar.c					\
			  fractal_celtic_mandelbrot.c			\
			  fractal_celtic_mandelbar.c			\
			  fractal_celtic_perpendicular.c		\
			  fractal_perpendicular_mandelbrot.c	\
			  fractal_perpendicular_burning_ship.c	\
			  fractal_perpendicular_buffalo.c		\
SRC = $(addprefix $(SRC_DIR), $(SRC_LST))

OBJ_DIR = ./objects/
OBJ_LST = $(patsubst %.c, %.o, $(SRC_LST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LST))

ifdef B
	SEL = $(OBJ_B)
else
	SEL = $(OBJ)
endif

all:			$(NAME)

bonus:
	make B=1 all

$(NAME):		$(LIBFT) $(MLX) $(OBJ_DIR) $(SEL)
	$(CC) $(FLAGS) $(LIB) $(INC) $(SEL) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c $(HDR)
	$(CC) $(FLAGS) -c $(INC) $< -o $@

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	$(MAKE) -sC $(MLX_DIR)

clean:
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(MAKE) -sC $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(MLX) $(LIBFT) $(NAME)

re:
	$(MAKE) fclean all

.PHONY: all clean fclean re bonus
