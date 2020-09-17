# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estina <estina@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 13:13:02 by estina            #+#    #+#              #
#    Updated: 2020/09/18 00:17:07 by estina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

DIR = srcs

OBJDIR = objs

LIBPATH = Libft/Libft

LIB = $(LIBPATH)/libft.a

SRCS =		flag_minus_handle.c		flag_none_handle.c				\
			flag_point_handle.c		flag_zero_handle.c				\
			handle_char.c			handle_float.c					\
			handle_n.c				handle.c						\
			handle_pointer.c		handle_string.c					\
			handle_types.c			hex_itoa.c						\
			long_long_itoa.c		unsigned_itoa.c					\
			long_itoa.c				unsigned_long_itoa.c
			

PRSRC = ft_printf.c

SRC = $(addprefix $(DIR)/,$(SRCS))

SRCS_LIB =	ft_putstr_fd.c		ft_putchar_fd.c		ft_strdup.c		\
			ft_strlen.c			ft_itoa.c			ft_atoi.c		\
			ft_isdigit.c		ft_strjoin.c		ft_strncmp.c

PR = $(addprefix $(OBJDIR)/,$(PRSRC:.c=.o))

OBJ = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

OBJ_LIB = $(addprefix $(OBJDIR)/,$(SRCS_LIB:.c=.o))

HEADERS = -I ./ -I $(LIBPATH)

all: $(NAME)

$(LIB):
	-@make -C $(LIBPATH)
	-@mkdir -p $(OBJDIR) $(OBJPR)
	-@cd objs && ar -x ../$(LIBPATH)/libft.a

$(NAME): $(LIB) $(OBJ) $(PR)
	-@ar rcs $(NAME) $(OBJ) $(PR) $(OBJ_LIB)

bonus: $(LIB) $(OBJ) $(PR)
	-@ar rcs $(NAME) $(OBJ) $(PR) $(OBJ_LIB)

$(OBJDIR)/%.o: $(DIR)/%.c Makefile
	-@$(CC) -o $@ -c $< $(HEADERS) $(CFLAGS)

$(OBJDIR)/%.o: %.c Makefile
	-@$(CC) -o $@ -c $< $(HEADERS) $(CFLAGS)

clean:
	-@rm -rf $(OBJDIR)
	-@make -s -C $(LIBPATH) clean

fclean: clean
	-@rm -f $(NAME) test
	-@make -s -C $(LIBPATH) fclean

re: fclean all

test: re
	-@rm -f a.out
	-@$(CC) $(CFLAGS) $(NAME) main.c

a:
	-@rm -f a.out

.PHONY: all, clean, fclean, re, test
