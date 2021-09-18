NAME = so_long.a

HEADER_DIR = ./header

SOURCE_DIR = ./src
MLX_DIR = ./mlx

MLX_HEADER = ${HEADER_DIR}/so_long.h
MLX_LIB = ${MLX_DIR}/libmlx.a

SOURCES = ${SOURCE_DIR}/test.c ${SOURCE_DIR}/init.c

RM = @rm -f

CC = @clang

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L mlx -lmlx -lXext -lX11 -lm -lz

OBJECTS = ${SOURCES:.c=.o}

MSG1 = @echo "Compiled ✔︎"
MSG2 = @echo "Cleaned ✔︎"

all: 		${NAME}

$(NAME): ${OBJECTS} ${MLX_LIB} ${MLX_HEADER} ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} ${MLX_LIB} ${MLX_FLAGS}  -o ${NAME}
	${MSG1}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM}	${OBJECTS}
	${MSG2}

fclean: clean
	${RM} ${NAME}

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