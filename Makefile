NAME	=	push_swap

SRCS	=	push_swap.c\
			init.c\
			fill_data.c\
			error.c\

OPTION	=	-I includes -I libft

OBJDIR	=	objs

OBJS	=	${addprefix ${OBJDIR}/,${SRCS:.c=.o}}

LFT		=	libft/libft.a

CC		=	clang

CFLAGS	=	-Werror -Wall -Wextra

all : ${OBJDIR} ${NAME}

${OBJS}: ${OBJDIR}/%.o: %.c
	${CC} -c ${CFLAGS} ${OPTION} $< -o $@

${OBJDIR}:
	@mkdir -p $@

${LFT}:
	make -C libft/

${NAME}: ${LFT} ${OBJS}
	${CC} ${CFLAGS} $^ -o $@

clean:
	make -C libft clean
	rm -rf ${OBJDIR}

fclean: clean
	make -C libft fclean
	rm -rf ${NAME}

re: fclean all