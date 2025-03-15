# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 19:22:02 by subjeong          #+#    #+#              #
#    Updated: 2025/03/07 20:06:38 by subjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
HEADERDIR = .
LIBDIR	= libft
LIBFILE	= $(LIBDIR)/libft.a

SRCS = $(SRCDIR)/so_long.c
OBJS = $(SRCS:.c=.o)

NAME = so_long

all : $(LIBFILE) $(NAME)

$(LIBFILE) :
	make -C $(LIBDIR)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)

%.o : %.c $(HEADERDIR)/so_long.h
	$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)

re: fclean all

.PHONY: $(NAME) all clean fclean re