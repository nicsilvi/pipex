# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smercado <smercado@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 16:23:55 by smercado          #+#    #+#              #
#    Updated: 2024/08/08 15:07:12 by smercado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEAD = pipex.h
SRC = pipex.c childs.c free_clean_error.c

OBJS = ${SRC:.c=.o}

LIB = src/libft/libft.a
AR = ar rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RANLIB = ranlib

all : libft $(NAME)

libft : 
		make -C src/libft

$(NAME):	$(OBJS) $(HEAD)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	$(RANLIB) $(LIB)

%.o : %.c $(HEAD) Makefile
		$(CC) -I. $(CFLAGS) -c $< -o $@

clean:
	make clean -C src/libft
	rm -f $(OBJS) 

fclean: clean
	make fclean -C src/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re all libft
