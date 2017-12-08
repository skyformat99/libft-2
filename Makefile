NAME = libft.a
SRCS = *.c
OBJECTS = *.o
FLAGS = -Wall -Wextra -Werror
INDEX = index

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
