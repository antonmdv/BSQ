# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hryu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 13:29:40 by hryu              #+#    #+#              #
#    Updated: 2018/08/13 13:35:48 by hryu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = *.c

all:
	gcc -Wall -Wextra -Werror $(SRCS) -o $(NAME)

clean:
	/bin/rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
