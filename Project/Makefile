# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 20:18:04 by nfauconn          #+#    #+#              #
#    Updated: 2024/01/26 20:18:05 by nfauconn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft
CC = clang
INCLUDES = -I includes/push_swap.h
CFLAGS	= -Wall -Wextra -Werror
SRCS =  cdbll_change_end.c\
		cdbll_change_top.c\
		cdbll_is_sorted.c\
		cdbll_len.c\
		do_push.c\
		do_reverse_rotate.c\
		do_rotate.c\
		do_swap.c\
		error.c\
		find_max_min.c\
		find_moves_b.c\
		find_moves_down_to_top.c\
		find_moves_up_to_top.c\
		find_quantiles.c\
		free_pushswap.c\
		init.c\
		parse.c\
		push_swap_utils.c\
		main.c\
		sort_less_5.c\
		sort_less_40.c\
		sort_more_40.c\
		sort_more_40_utils.c\
		sorted_push_to_a.c\

OBJS = ${SRCS:.c=.o}

all: $(NAME)

${NAME}: ${OBJS}
	@echo create: $(@:%=%)
	@${CC} ${CFLAGS} ${INCLUDES} ${OBJS} -o ${NAME}

.c.o:
	@${CC} ${CFLAGS} ${INCLUDES} -g -c $< -o ${<:.c=.o}

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re