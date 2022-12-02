NAME		= fractol

CC			= cc
CCFLAG		= -Wall -Wextra -Werror -fsanitize=address
LIB			= $(FT) $(MLX)	\
			  -framework OpenGL -framework AppKit
RM			= rm -f

FT_DIR		= ./ft/
FT_HDR		= $(FT_DIR)ft.h
FT			= $(FT_DIR)libft.a

MLX_DIR		= ./mlx/
MLX_HDR		= $(MLX_DIR)mlx.h
MLX			= $(MLX_DIR)libmlx.a

SRC_DIR		= ./src/
SRC_LST		= main.c		\
			  execute.c		\
			  event.c		\
			  quit.c		\
			  scroll_up.c	\
			  scroll_down.c	\
			  mlx_extend.c
SRC			= $(addprefix $(SRC_DIR), $(SRC_LST))

SRC_B_DIR	= ./src/
SRC_B_LST	= main_bonus.c
SRC_B		= $(addprefix $(SRC_B_DIR), $(SRC_B_LST))

ifdef B
	SEL = $(SRC_B)
else
	SEL = $(SRC)
endif

$(NAME): $(FT) $(MLX) $(SEL)
	$(CC) $(CCFLAG) $(SEL) $(LIB) -o $(NAME)

$(FT):
	make -sC $(FT_DIR)

$(MLX):
	make -sC $(MLX_DIR)

all: $(NAME)

bonus:
	make B=1 all

clean:
	make -sC $(FT_DIR) clean
	make -sC $(MLX_DIR) clean

fclean: clean
	$(RM) $(FT) $(MLX) $(NAME)

re:
	make fclean all

.PHONY: all bonus clean fclean re
