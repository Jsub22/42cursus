# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 09:13:51 by subjeong          #+#    #+#              #
#    Updated: 2024/12/20 16:29:48 by subjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBDIR	= libft
LIBFILE	= libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCDIR = .
HEADERDIR = .

SRCS =	$(SRCDIR)/ft_print_hex.c \
		$(SRCDIR)/ft_print_unsigned.c \
		$(SRCDIR)/ft_print_ptr.c \
		$(SRCDIR)/ft_print_utils.c \
		$(SRCDIR)/ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIBDIR)/
	cp $(LIBDIR)/$(LIBFILE) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBDIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBDIR)

re: clean all

.PHONY: all clean fclean re