# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: machoffa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 13:13:16 by machoffa          #+#    #+#              #
#    Updated: 2020/02/08 14:14:09 by machoffa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -Wall -Wextra -Werror -I.

MAKE = make -C

DIR = ./

PATH_SRC = ./srcs/

SRCS = $(PATH_SRC)lemin.c \
	  $(PATH_SRC)lemin2.c \
	  $(PATH_SRC)nbchemin.c \
	  $(PATH_SRC)bfs.c \
	  $(PATH_SRC)main.c \
	  $(PATH_SRC)tools.c \
	  $(PATH_SRC)print.c \
	  $(PATH_SRC)parsingroom.c \
	  $(PATH_SRC)parsingtunnel.c \

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft/

all: lib $(NAME)

lib:
	$(MAKE) ./libft

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	gcc $(CFLAGS) $(SRCS) -L./libft -lft -o $(NAME)

%.o: %.c ./lemin.h ./Makefile ./libft/libft.h
	gcc -o $@ -c $< $(CFLAGS)

clean:
	rm -f srcs/*.o
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.PHONY : all lib clean fclean re
