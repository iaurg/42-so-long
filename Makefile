NAME = so_long
NAME_BONUS = so_long_bonus

HEADER_DIR = ./header

SOURCE_DIR = ./src
SOURCE_BONUS_DIR = ./src_bonus

MLX_DIR = ./libs/mlx
LBFT_DIR = ./libs/libft

MLX_HEADER = ${HEADER_DIR}/so_long.h
MLX_HEADER_BONUS = ${HEADER_DIR}/so_long_bonus.h
MLX_LIB = ${MLX_DIR}/libmlx.a
LBFT_LIB = ${LBFT_DIR}/libft.a

SOURCES_FILES = init.c print_error.c validate_map.c
SOURCES_FILES += map_init.c game_init.c key_hooks.c
SOURCES_FILES += img_init.c exit_game.c
SOURCES_FILES += move_elements.c map_and_validate_elements.c

SOURCES_BONUS_FILES = init.c print_error.c validate_map.c
SOURCES_BONUS_FILES += map_init.c game_init.c key_hooks.c
SOURCES_BONUS_FILES += img_init.c exit_game.c
SOURCES_BONUS_FILES += move_elements.c map_and_validate_elements.c
SOURCES_BONUS_FILES += animate_hook.c animate_coin.c

RM = @rm -f

CC = @clang

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L. -lXext -L. -lX11

SOURCES = $(addprefix $(SOURCE_DIR)/, $(SOURCES_FILES))
SOURCES_BONUS = $(addprefix $(SOURCE_BONUS_DIR)/, $(SOURCES_BONUS_FILES))

OBJECTS = ${SOURCES:.c=.o}
OBJECTS_BONUS = ${SOURCES_BONUS:.c=.o}

MSG1 = @echo "Compiled ✔︎"
MSG2 = @echo "Cleaned ✔︎"

all: ${NAME}

bonus: ${NAME_BONUS}

$(NAME): ${LBFT_LIB} ${OBJECTS} ${MLX_LIB} ${MLX_HEADER} ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} ${LBFT_LIB} ${MLX_LIB} ${MLX_FLAGS} -o ${NAME}
	${MSG1}

$(NAME_BONUS): ${LBFT_LIB} ${OBJECTS_BONUS} ${MLX_LIB} ${MLX_HEADER_BONUS} ${OBJECTS_BONUS}
	${CC} ${CFLAGS} ${OBJECTS_BONUS} ${LBFT_LIB} ${MLX_LIB} ${MLX_FLAGS} -o ${NAME_BONUS}
	${MSG1}

${LBFT_LIB}:
	@${MAKE} -C ${LBFT_DIR}

${MLX_LIB}:
	@${MAKE} -C ${MLX_DIR}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM}	${OBJECTS} ${OBJECTS_BONUS}
	@${MAKE} fclean -C ${LBFT_DIR}
	${MSG2}

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}
	@${MAKE} fclean -C ${LBFT_DIR}

run:
	${MAKE} && ./so_long.a
	${MSG1}

normiall:
	norminette ${SOURCE_DIR}
	norminette ${HEADER_DIR}

# Regenerate compilation
re: fclean all

# phony will run, independent from the state of the file system, avoid make in files with same name
.PHONY: all clean fclean re
