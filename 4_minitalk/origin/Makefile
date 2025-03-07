# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 17:07:00 by subjeong          #+#    #+#              #
#    Updated: 2025/03/05 17:07:01 by subjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
HEADERDIR = .

CLIENT_SRCS = $(SRCDIR)/client.c
SERVER_SRCS = $(SRCDIR)/server.c
UTILS_SRCS = $(SRCDIR)/utils.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
UTILS_OBJS = $(UTILS_SRCS:.c=.o)

CLIENT_NAME = client
SERVER_NAME = server

all : $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(UTILS_OBJS) -o $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(UTILS_OBJS) -o $(SERVER_NAME)

%.o : %.c $(HEADERDIR)/minitalk.h
	$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_OBJS)
	rm -f $(UTILS_OBJS)

fclean: clean
	rm -f $(CLIENT_NAME)
	rm -f $(SERVER_NAME)

re: fclean all

.PHONY: $(CLIENT_NAME) $(SERVER_NAME) all clean fclean re