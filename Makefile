NAME = so_long

HEADER_DIR = ./header

SOURCE_DIR = ./src
MLX_DIR = ./libs/mlx
LBFT_DIR = ./libs/libft

MLX_HEADER = ${HEADER_DIR}/so_long.h
MLX_LIB = ${MLX_DIR}/libmlx.a
LBFT_LIB = ${LBFT_DIR}/libft.a

SOURCES = ${SOURCE_DIR}/init.c ${SOURCE_DIR}/print_error.c ${SOURCE_DIR}/validate_map.c
SOURCES += ${SOURCE_DIR}/map_init.c ${SOURCE_DIR}/game_init.c ${SOURCE_DIR}/key_hooks.c
SOURCES += ${SOURCE_DIR}/img_init.c ${SOURCE_DIR}/exit_game.c
SOURCES += ${SOURCE_DIR}/move_elements.c ${SOURCE_DIR}/map_and_validate_elements.c

RM = @rm -f

CC = @clang

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L mlx -lmlx -lXext -lX11 -lm -lz

OBJECTS = ${SOURCES:.c=.o}

MSG1 = @echo "Compiled ✔︎"
MSG2 = @echo "Cleaned ✔︎"

all: ${NAME}

$(NAME): ${LBFT_LIB} ${OBJECTS} ${MLX_LIB} ${MLX_HEADER} ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} ${LBFT_LIB} ${MLX_LIB} ${MLX_FLAGS} -o ${NAME}
	${MSG1}

${LBFT_LIB}:
	@${MAKE} -C ${LBFT_DIR}

${MLX_LIB}:
	@${MAKE} -C ${MLX_DIR}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM}	${OBJECTS}
	@${MAKE} fclean -C ${LBFT_DIR}
	${MSG2}

fclean: clean
	${RM} ${NAME}
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
