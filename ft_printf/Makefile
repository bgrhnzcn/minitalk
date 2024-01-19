SRCS = ft_printf.c ft_printf_utils.c ft_putchar.c ft_putstr.c \
	ft_putnbr.c ft_putnbr_hex.c ft_putnbr_pointer.c ft_putunbr.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all