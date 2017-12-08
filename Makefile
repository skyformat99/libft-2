NAME = libft.a
SRCS = *.c
OBJECTS = *.o
INC = .
FLAGS = -Wall -Werror -Wextra
INDEX = index

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS) -I$(INC)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
