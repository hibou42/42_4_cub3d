#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -Wno-deprecated

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

BLUE		= 	\033[44m
BLUE_T		= 	\033[0;34m
GREEN		=	\033[1;32m
RED			=	\033[1;31m
ENDCOLOR	=	\033[0m

START 		= 	echo "$(BLUE_T)MiniLibX compilation started\n$(ENDCOLOR)"
END 		= 	echo "$(BLUE_T)\nMiniLibX compilation done\n$(ENDCOLOR)"
OK			=	echo "$(BLUE_T)OK$(ENDCOLOR)"
CHARG_LINE	=	echo "$(BLUE)    $(ENDCOLOR)"

all: start $(NOM)

start:
		@${START}

end:	
		@${END}

%.o: %.c
		@cc ${CFLAGS} -c $< -o $@
		@${OK}

%.o: %.m
		@cc ${CFLAGS} -c $< -o $@
		@${OK}

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)
	@$(END)

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
