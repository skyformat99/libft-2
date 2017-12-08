NAME = libft.a
SRCS = *.c
OBJECTS = *.o
FLAGS = -Wall -Werror -Wextra
INDEX = index

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
