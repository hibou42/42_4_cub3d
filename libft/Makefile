#***** Name *****#

NAME	= libft.a

#***** Sources / Objs *****#

SRCS	=	ft_atoi.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_strchr.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memcmp.c \
			ft_memchr.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_split.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_printf.c \
			core_c.c \
			core_s.c \
			core_di.c \
			core_u.c \
			core_p.c \
			core_x.c \
			core_xx.c \
			ft_puthex.c \
			doubl_list/ft_dlst_add.c \
			doubl_list/ft_dlst_addback.c \
			doubl_list/ft_dlst_addfront.c \
			doubl_list/ft_dlst_clear.c \
			doubl_list/ft_dlst_delone.c \
			doubl_list/ft_dlst_newcontent.c \
			doubl_list/ft_pop_back.c \
			doubl_list/ft_pop_front.c \

OBJS	= ${SRCS:.c=.o}

#***** Flags *****#

CC	= gcc
AR = ar rcs
RM	= rm -f
CFLAGS	= -Wall -Werror -Wextra

#***** Colors *****#

GREEN			=		\033[1;32m
BLUE			=		\033[44m
BLUE_T			=		\033[0;34m
RED				=		\033[1;31m
ENDCOLOR		=		\033[0m

#******Echo********#

START			=		echo "$(BLUE_T)LIBFT compilation started\n$(ENDCOLOR)"
END_COMP_LIB	=		echo "$(BLUE_T)LIBFT compilation done\n$(ENDCOLOR)"
END_CLEAN		=		echo "$(RED)Cleaning in progress$(ENDCOLOR)"
CHARG_LINE		=		echo "$(BLUE)    $(ENDCOLOR)\c"
BS_N			=		echo "\n"

#***** Message compilation // En phase de test //*****#

TOTAL_FILES_SRC	= $(words $(SRC))
COMPILED_FILE	= 0
MESSAGE			= "Compilation en cours : $(COMPILED_FILES)/63 ($(shell expr $(COMPILED_FILES) \* 100 / 63)%)"


#***** Compilation *****#

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: 	start ${NAME}

start:
		@${START}

%.o:	%.c
		@${CC} ${CFLAGS} -c $< -o $@
		$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
		@printf "$(BLUE_T)%s$(ENDCOLOR)" $(MESSAGE)
		@sleep 0.001
		@printf "\r"
# @$(CHARG_LINE)

${NAME}: ${OBJS}
#		@$(BS_N)
		@${AR} ${NAME} ${OBJS}
		@$(END_COMP_LIB)

#***** Clean *****#

clean:		
		@${RM} ${OBJS} ${OBJSB}
		@$(END_CLEAN)

fclean:		clean
		@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
