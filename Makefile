#***** Name *****#

NAME			=		cub3d

#***** Makeflags *****#

MAKEFLAGS += --no-print-directory

#***** Sources / Objs *****#

SRC				=		src/cub3d.c \
						src/verbose.c \
						src/init/struct.c \
						src/init/mlx.c \
						src/init/add_read_arg.c \
						src/parsing/parsing.c \
						src/parsing/parsing_utils.c \
						src/parsing/add_infos.c \
						src/parsing/add_map.c \
						src/parsing/update_map.c \
						src/parsing/convert.c \
						src/events/events.c \
						src/error/exit.c \
						src/error/arg.c \
						src/error/check_parsing.c \
						src/error/flood_feed.c \
						src/design/draw_pixel.c \


OBJS			=		$(SRC:.c=.o)

#***** Message compilation // En phase de test //*****#

TOTAL_FILES		= $(words $(SRC))
COMPILED_FILE	= 0
MESSAGE			= "Compilation en cours : $(COMPILED_FILES)/$(TOTAL_FILES) ($(shell expr $(COMPILED_FILES) \* 100 / $(TOTAL_FILES))%)"

#***** Libft / MiniLbx *****#

LIBFT			=		./libft/libft.a
MLXLIB			=		./mlx/libmlx.a
MINILBX			=		-Lmlx -lmlx -framework OpenGL -framework AppKit
MLIBFT			=		$(MAKE) -C libft
MMLX			=		$(MAKE) -C mlx

ifeq ($(shell uname), Linux)
MLXLIB			=		./mlx-linux/libmlx.a
MINILBX			=		-L ./mlx-linux/ -lmlx -Ilmlx -lXext -lX11
MMLX			=		$(MAKE) -C mlx-linux
endif

#***** Couleurs *****#

GREEN			=		\033[1;32m
BG_GREEN		=		\033[42m
BLUE			=		\033[0;94m
RED				=		\033[1;31m
GREY			=		\033[0;37m
ENDCOLOR		=		\033[0m

#***** Textes *****#

START			=		echo "$(GREEN)Compilation of $(NAME) started\n$(ENDCOLOR)"
TEST			=		echo "$(GREY)Running some test\n$(ENDCOLOR)"
END_COMP		=		echo "$(GREEN)Compilation is done$(ENDCOLOR)"
CLEAN_TXT		=		echo "$(RED)Deleting objects$(ENDCOLOR)"
FCLEAN_TXT		=		echo "$(RED)Deleting program$(ENDCOLOR)"
CHARG_LINE		=		echo "$(BG_GREEN)    $(ENDCOLOR)\c"
BS_N			=		echo "\n"

#***** Flags *****#

CC				=		gcc
CFLAGS			=		-Wall -Wextra -Werror -g
L				=		$(CFLAGS) -fsanitize=address
RM				=		rm -f

#***** Compilation *****#

all : logo lib start $(NAME)

lib:
			@$(MLIBFT) all
			@$(MMLX) all
			@$(END_COMP_LIB)

start:
			@tput setaf 2; cat ascii_art/cub3d; tput setaf default
			@$(START)

logo :
			@tput setaf 2; cat ascii_art/hibou; tput setaf default

%.o:		%.c ./libft/libft.h Makefile cub3d.h
			@$(CC) $(CFLAGS) -c $< -o $@
			$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
			@printf "$(GREEN)%s$(ENDCOLOR)" $(MESSAGE)
			@sleep 0.001
			@printf "\r"
# @$(CHARG_LINE)

$(NAME) :	${OBJS}
			@$(BS_N)
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${MLXLIB} ${MINILBX}
			@$(END_COMP)
			@tput setaf 2; cat ascii_art/small_hibou1; tput setaf default

l :			${OBJS}
			${MLIBFT} all
			@${CC} ${L} -o ${NAME} ${OBJS} ${LIBFT} ${MLXLIB} ${MINILBX}
			@$(END_COMP)	

#***** Clean *****#

clean:
			@$(CLEAN_TXT)
			@${RM} ${OBJS}
			@cd libft && make clean
			@cd mlx && make clean
			@tput setaf 1; cat ascii_art/trash; tput setaf default

fclean:		clean
			@$(FCLEAN_TXT)	
			@${RM} ${NAME}
			@cd libft && make fclean
			@cd mlx && make clean
			@rm -rf .DS_Store
			@echo "$(GREEN)Cleaning succes$(ENDCOLOR)"

re:			fclean all

.PHONY:		all clean fclean 
