# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lschambe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 15:13:27 by lschambe          #+#    #+#              #
#    Updated: 2018/12/23 19:11:56 by sgendry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAG = -Wall -Werror -Wextra
FILES = fillit.c \
		valid.c \
		libft/ft_strlen.c

$(NAME) :
	gcc $(FLAG) -o $(NAME) $(FILES)

all : $(NAME)

clean :

fclean : clean
	rm -rf $(NAME)

re : fclean all
