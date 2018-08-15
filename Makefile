
NAME = bsq
SRCS = src/*.c
INCLUDES = -I includes
COMPILE = gcc -Wall -Wextra -Werror

all:
	$(COMPILE) $(INCLUDES) main.c $(SRCS) -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
