NAME = so_long.a

HEADER_DIR = ./header

INCLUDES = -I${HEADER_DIR}

SOURCE_DIR = ./src

#SOURCES = $(SOURCE_DIR)/main.c
SOURCES = $(SOURCE_DIR)/main.c

RM = @rm -f

ARCHIVE = @ar -rc

CC = @clang

CFLAGS = -Wall -Wextra -Werror
# MINIFLAGS = -Lmlx_linux -lmlx_linux -L/usr/local/lib -Imlx_linux -lXext -lX11 -lm -lz -o

OBJECTS = ${SOURCES:.c=.o}

MSG1 = @echo "Compiled ✔︎"
MSG2 = @echo "Cleaned ✔︎"

# Mandatory
all: 		${NAME}

#%.o: %.c
#	${CC} ${CFLAGS} -I/usr/local/include -Imlx_linux -O3 -c $< -o $@

# Mandatory
$(NAME): ${OBJECTS}
	${ARCHIVE} ${NAME} ${OBJECTS}
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