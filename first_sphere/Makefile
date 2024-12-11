NAME			= sphere
SRCS			= 	main.c \
#					read_main.c \

OBJ_DIR 		= obj
FLAGS			= -Wall -Wextra -Werror -lm
CC				= gcc
RM				= rm -f

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

LIBFT_DIR		= librairies/libft
LIBFT 			= ./${LIBFT_DIR}/libft.a
MINILIBX_DIR	= librairies/minilibx_linux
MINILIBX		= ./${MINILIBX_DIR}/libmlx.a

all: $(NAME)

$(NAME): ${OBJ}
		@(make -s -C ${LIBFT_DIR})
		@(make -s -C ${MINILIBX_DIR})
		@(${CC} ${FLAGS} -o $@ $^ ${PRINTF} ${LIBFT} ${MINILIBX}) #OpenGL -framework AppKit

$(OBJ_DIR)/%.o: %.c
		@(mkdir -p $(OBJ_DIR))
		@(${CC} ${FLAGS} -c $< -o $@)


$(OBJB_DIR)/%.o: %.c
		mkdir -p $(OBJB_DIR)
		${CC} ${FLAGS} -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)
		make clean -C ${LIBFT_DIR}
		make clean -C ${MINILIBX_DIR}
		$(RM) $(OBJB)
		$(RM) $(OBJ)

fclean:		clean
		make fclean -C ${LIBFT_DIR}
		make clean -C ${MINILIBX_DIR}
		$(RM) $(NAME)
 
re:			fclean	all

.PHONY:		all re clean fclean