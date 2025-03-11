# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 15:31:42 by subjeong          #+#    #+#              #
#    Updated: 2025/03/11 16:41:25 by subjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
HEADERDIR = .
LIBDIR	= libft
LIBFILE	= $(LIBDIR)/libft.a

CLIENT_SRCS = $(SRCDIR)/client.c
SERVER_SRCS = $(SRCDIR)/server.c
UTILS_SRCS = $(SRCDIR)/sigaction.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
UTILS_OBJS = $(UTILS_SRCS:.c=.o)

CLIENT_NAME = client
SERVER_NAME = server

all : $(LIBFILE) $(CLIENT_NAME) $(SERVER_NAME)

$(LIBFILE) :
	make -C $(LIBDIR)

$(CLIENT_NAME) : $(CLIENT_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(UTILS_OBJS) -L$(LIBDIR) -lft -o $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(UTILS_OBJS) -L$(LIBDIR) -lft -o $(SERVER_NAME)

%.o : %.c $(HEADERDIR)/minitalk.h
	$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_OBJS)
	rm -f $(UTILS_OBJS)
	make clean -C $(LIBDIR)

fclean: clean
	rm -f $(CLIENT_NAME)
	rm -f $(SERVER_NAME)
	make fclean -C $(LIBDIR)

re: fclean all

.PHONY: all clean fclean re