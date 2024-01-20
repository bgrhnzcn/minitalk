SRCS = client.c server.c

BONUS_SRCS = client_bonus.c server_bonus.c

OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

CC = gcc

NAME = minitalk

CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -c -Ilibft -Ift_printf $?

all: $(NAME)

$(NAME): libs $(OBJ) client server 

server:
	$(CC) $(CFLAGS) -o server server.o libft/libft.a ft_printf/libftprintf.a

client:
	$(CC) $(CFLAGS) -o client client.o libft/libft.a ft_printf/libftprintf.a

server_bonus:
	$(CC) $(CFLAGS) -o server server_bonus.o libft/libft.a ft_printf/libftprintf.a

client_bonus:
	$(CC) $(CFLAGS) -o client client_bonus.o libft/libft.a ft_printf/libftprintf.a

libs:
	cd libft && make
	cd ft_printf && make

bonus: libs $(BONUS_OBJ) client_bonus server_bonus

clean:
	rm -f *.o
	cd libft && make fclean
	cd ft_printf && make fclean

fclean: clean
	rm -f server
	rm -f client

re: fclean all

.PHONY: all re client server libs clean fclean