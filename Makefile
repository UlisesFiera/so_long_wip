NAME 					= so_long

LIBFT					= ./src/libft/libft.a

CC						= gcc

STD_FLAGS				= -Wall -Wextra -Werror -fPIE
MLX_FLAGS				= -Lsrc/minilibx-linux -lmlx_Linux -lX11 -lXext

SRCS					= src/main.c \
						  src/wall_check.c \
						  src/char_check.c \
						  src/load_textures.c \
						  src/texture_put.c \
						  src/backtracking.c \
						  src/free_load.c \
						  src/triggers.c \
						  src/map_copy.c \
						  src/free_matrix.c \
						  src/collision.c \
						  src/background.c \
						  src/move.c \
						  src/close_window.c \
						  src/collection.c \
						  src/map_utils.c \

OBJS					= ${SRCS:.c=.o}

REMOVE					= rm -f ${OBJS}; rm -f so_long; rm -f *.out

all:					${LIBFT} ${NAME}

${NAME}:
						${CC} ${SRCS} ${LIBFT} ${STD_FLAGS} ${MLX_FLAGS} -o ${NAME}

${LIBFT}:				
						make bonus -C ./src/libft

clean:
						${REMOVE}

fclean:					clean
						make fclean -C ./src/libft
						
re:						clean all

.PHONY:					all clean fclean re