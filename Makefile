# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgendry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 18:09:46 by sgendry           #+#    #+#              #
#    Updated: 2018/12/27 15:19:09 by sgendry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAG = -Wall -Werror -Wextra

OBJ = $(patsubst %.c,%.o,$(wildcard *.c))

LIB_OBJ = $(patsubst %.c,%.o,$(wildcard libft/*.c))

all: $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	gcc $(FLAG) $^ -o $@

%.o: %.c
	gcc $(FLAG) -c $^ -o $@ -Ilibft

clean:
	rm -f *.o
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/*.o

re : fclean all

.PHONY: all clean fclean re
