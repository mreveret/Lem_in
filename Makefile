# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: machoffa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 13:13:16 by machoffa          #+#    #+#              #
#    Updated: 2019/11/25 15:00:58 by machoffa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -Wall -Wextra -Werror -I.

DIR = ./

PATH_SRC = ./srcs/

SRCS = $(PATH_SRC)lemin.c \
	  $(PATH_SRC)main.c \

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	gcc $(CFLAGS) $(SRCS) -L./libft -lft -o $(NAME)

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS)

clean:
	rm -f srcs/*.o
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re
