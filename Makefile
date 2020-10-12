NAME = libftprintf.a
HEAD = printf.h

SRCS =	convert.c handler.c \
		parse.c printf.c \
		./libft/ft_atoi.c ./libft/ft_calloc.c \
		./libft/ft_isdigit.c ./libft/ft_memset.c \
		./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c \
		./libft/ft_strdup.c ./libft/ft_strjoin.c \
		./libft/ft_strlen.c ./libft/ft_substr.c

OBJS = $(SRCS:%.c=%.o)

%.o : %.c $(HEAD)
	gcc -Wall -Wextra -Werror -c $< -o $@

all: $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f *.o
	rm -f ./libft/*.o

fclean: clean
	rm -f $(NAME);

re: fclean all

.PHONY: all clean fclean re
