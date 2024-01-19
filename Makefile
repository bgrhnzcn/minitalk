SRCS = client.c server.c

OBJ = $(SRCS:.c=.o)

CC = gcc

NAME = minitalk

CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -c -Ilibft -Ift_printf $?

all: $(NAME)

$(NAME): libs $(OBJ) server client

server:
	$(CC) $(CFLAGS) -o server server.o libft/libft.a ft_printf/libftprintf.a

client:
	$(CC) $(CFLAGS) -o client client.o libft/libft.a ft_printf/libftprintf.a

libs:
	cd libft && make
	cd ft_printf && make

clean:
	rm -f *.o
	cd libft && make fclean
	cd ft_printf && make fclean

fclean: clean
	rm -f server
	rm -f client

re: fclean all

.PHONY: all re client server libs clean fclean