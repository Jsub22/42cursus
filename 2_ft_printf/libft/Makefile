# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 18:27:49 by subjeong          #+#    #+#              #
#    Updated: 2024/10/24 16:23:51 by subjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCDIR = .
HEADERDIR = .

SRCS =	$(SRCDIR)/ft_isalpha.c $(SRCDIR)/ft_isdigit.c $(SRCDIR)/ft_isalnum.c \
		$(SRCDIR)/ft_isascii.c $(SRCDIR)/ft_isprint.c $(SRCDIR)/ft_strlen.c \
		$(SRCDIR)/ft_memset.c $(SRCDIR)/ft_bzero.c $(SRCDIR)/ft_memcpy.c \
		$(SRCDIR)/ft_memmove.c $(SRCDIR)/ft_strlcpy.c $(SRCDIR)/ft_strlcat.c \
		$(SRCDIR)/ft_toupper.c $(SRCDIR)/ft_tolower.c $(SRCDIR)/ft_strchr.c \
		$(SRCDIR)/ft_strrchr.c $(SRCDIR)/ft_strncmp.c $(SRCDIR)/ft_memchr.c \
		$(SRCDIR)/ft_memcmp.c $(SRCDIR)/ft_strnstr.c $(SRCDIR)/ft_atoi.c \
		$(SRCDIR)/ft_calloc.c $(SRCDIR)/ft_strdup.c \
		$(SRCDIR)/ft_substr.c $(SRCDIR)/ft_strjoin.c $(SRCDIR)/ft_strtrim.c \
		$(SRCDIR)/ft_itoa.c $(SRCDIR)/ft_putchar_fd.c $(SRCDIR)/ft_putstr_fd.c \
		$(SRCDIR)/ft_putendl_fd.c $(SRCDIR)/ft_putnbr_fd.c $(SRCDIR)/ft_striteri.c \
		$(SRCDIR)/ft_strmapi.c $(SRCDIR)/ft_split.c
SRCS_B = $(SRCDIR)/ft_lstnew_bonus.c $(SRCDIR)/ft_lstadd_front_bonus.c $(SRCDIR)/ft_lstadd_back_bonus.c \
		$(SRCDIR)/ft_lstclear_bonus.c $(SRCDIR)/ft_lstdelone_bonus.c $(SRCDIR)/ft_lstsize_bonus.c \
		$(SRCDIR)/ft_lstlast_bonus.c $(SRCDIR)/ft_lstiter_bonus.c $(SRCDIR)/ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
	OBJ = $(OBJS_B)
else
	OBJ = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

bonus:
	$(MAKE) WITH_BONUS=1

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
