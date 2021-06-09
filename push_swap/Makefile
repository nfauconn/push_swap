NAME	=	push_swap

SRCS	=	srcs/parsing.c\

INC		=	-I includes -I libft

OBJDIR	=	objs

OBJS	=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

LFT		=	libft/libft.a

CFLAGS	=	-Werror -Wall -Wextra

all : $(OBJDIR) $(NAME)

$(OBJS): $(OBJDIR)/%.o: %.c
	gcc -c $(CFLAGS) $(INC) $< -o $@

$(OBJDIR):
	@mkdir -p $@

$(LFT):
	make -C libft/

$(NAME): $(LFT) $(OBJS)
	cc $(CFLAGS) $^ -o $@ 
clean:
	make -C libft clean
	/bin/rm -rf $(OBJDIR)

fclean: clean
	make -C libft fclean
	/bin/rm -rf $(NAME)

re: fclean all