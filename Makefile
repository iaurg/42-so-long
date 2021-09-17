NAME = so_long.a

HEADER_DIR = ./header

INCLUDES = -I${HEADER_DIR}

SOURCE_DIR = ./src
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
#SOURCES = $(SOURCE_DIR)/main.c
SOURCES = $(SOURCE_DIR)/test.c

RM = @rm -f
RANLIB = @ranlib

ARCHIVE = @ar -rc

CC = @clang

CFLAGS = -Wall -Wextra -Werror
MINIFLAGS = -I mlx -L mlx -lmlx -lXext -lX11 -lm -lz

OBJECTS = ${SOURCES:.c=.o}

MSG1 = @echo "Compiled ✔︎"
MSG2 = @echo "Cleaned ✔︎"

# Mandatory
all: 		${NAME}

#%.o: %.c
#	${CC} ${CFLAGS} -I/usr/local/include -Imlx_linux -O3 -c $< -o $@

# Mandatory
$(NAME): ${OBJECTS} ${MLX_LIB} 
	${ARCHIVE} ${NAME} ${OBJECTS}
	${RANLIB} ${NAME}
	${MSG1}
#$(NAME): ${OBJECTS} ${LIBFT}
#	${MINIFLAGS} ${NAME}
#	${ARCHIVE} ${NAME} ${OBJECTS}
#	${RANLIB} ${NAME}
#	${MSG1}

.c.o:
		${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

# Mandatory
clean:
	${RM}	${OBJECTS}
	${MSG2}

# Mandatory
fclean: clean
	${RM} ${NAME}

# Mandatory
# Regenarate compilation
re: fclean all

# phony will run, independent from the state of the file system, avoid make in files with same name
.PHONY: all clean fclean re