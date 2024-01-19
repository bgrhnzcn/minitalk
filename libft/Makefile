SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
	ft_substr.c ft_strjoin.c  ft_split.c  ft_strmapi.c ft_putnbr_fd.c\
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strtrim.c ft_itoa.c\
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_arrays.c\

ifeq ($(USE_MATH),-D USE_MATH=1)
	SRCS += ft_vec_conv.c ft_vec2_double.c ft_vec2_op.c ft_vec2_vec2.c ft_vec3_double.c\
		ft_vec3_vec3.c ft_vec3_op.c ft_vec4_double.c ft_vec4_op.c ft_vec4_vec4.c\
		ft_mtx3_basic.c ft_utils.c ft_mtx4_basic.c ft_bresenham_line.c ft_drawing.c ft_maps.c\
		ft_colors.c
endif

ifeq ($(USE_MATH),-D USE_MATH=1)
%.o: %.c
	$(CC) $(FLAGS) $(USE_MATH) -c $<
else
%.o: %.c
	$(CC) $(FLAGS) -c $<
endif

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): ${OBJECTS}
	ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean math