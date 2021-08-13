NAME	=	push_swap

SRCS	=	annex_sorted_array.c\
			atoi_pushswap.c\
			cdbll_change_end.c\
			cdbll_change_top.c\
			cdbll_is_sorted.c\
			cdbll_len.c\
			do_push.c\
			do_rotate.c\
			do_reverse_rotate.c\
			do_swap.c\
			error.c\
			find_fewer_moves.c\
			find_max_min.c\
			find_median.c\
			free_pushswap.c\
			init.c\
			parse.c\
			push_swap.c\
			sort_less_5.c\
			sort_less_100.c\

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