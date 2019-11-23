# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estina <estina@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 13:13:02 by estina            #+#    #+#              #
#    Updated: 2019/11/10 14:28:03 by estina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_memset.c		ft_toupper.c	ft_strtrim.c	\
			ft_bzero.c		ft_tolower.c	ft_split.c		\
			ft_memcpy.c		ft_strchr.c		ft_itoa.c		\
			ft_memccpy.c	ft_strrchr.c	ft_strmapi.c	\
			ft_memmove.c	ft_strncmp.c	ft_putchar_fd.c	\
			ft_memchr.c		ft_strlcpy.c	ft_putstr_fd.c	\
			ft_memcmp.c		ft_strlcat.c	ft_putendl_fd.c	\
			ft_strlen.c		ft_strnstr.c	ft_putnbr_fd.c	\
			ft_isalpha.c	ft_atoi.c						\
			ft_isdigit.c	ft_calloc.c						\
			ft_isalnum.c	ft_strdup.c						\
			ft_isascii.c	ft_substr.c						\
			ft_isprint.c	ft_strjoin.c

BONS	=	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c	\
			ft_lstsize_bonus.c		ft_lstlast_bonus.c		\
			ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	\
			ft_lstclear_bonus.c		ft_lstiter_bonus.c		\
			ft_lstmap_bonus.c

GCC		=	@gcc -Wall -Wextra -Werror

OBJECTS	=	$(SRCS:.c=.o)

BOBJ	=	$(BONS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS) libft.h
	-$(GCC) -I./ -c $(SRCS)
	-@ar rc $(NAME) $(OBJECTS)
	-@ranlib $(NAME)

bonus: $(BONS) $(SRCS) libft.h
	-$(GCC) -I./ -c $(BONS) $(SRCS)
	-@ar rc $(NAME) $(BOBJ) $(OBJECTS)
	-@ranlib $(NAME)

clean:
	-@rm -f $(OBJECTS) $(BOBJ)

fclean: clean
	-@rm -f $(NAME)

re: fclean all
