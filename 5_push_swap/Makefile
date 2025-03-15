# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 03:06:52 by subjeong          #+#    #+#              #
#    Updated: 2025/03/14 20:18:10 by subjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
HEADERDIR = .

SRCS =	$(SRCDIR)/main.c \
		$(SRCDIR)/swap_ab.c \
		$(SRCDIR)/push_ab.c \
		$(SRCDIR)/rotate_ab.c \
		$(SRCDIR)/rrotate_ab.c \
		$(SRCDIR)/stack.c \
		$(SRCDIR)/validation.c \
		$(SRCDIR)/push_swap.c \
		$(SRCDIR)/utils.c \
		$(SRCDIR)/error.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c $(HEADERDIR)/main.h
	$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: $(NAME) all clean fclean re