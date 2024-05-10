# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:26:43 by lburkins          #+#    #+#              #
#    Updated: 2024/05/06 13:36:51 by lburkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFILES	=	ft_atoi.c \
			ft_atol.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_split.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_printf.c \
			ft_printf_print_csp.c \
			ft_printf_print_diux.c \
			get_next_line.c \
			get_next_line_utils.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

ANSI_GREEN := \033[0;32m
ANSI_CYAN := \033[0;36m
ANSI_RESET := \033[0m

all: $(NAME)

$(NAME): $(OFILES)
	@ar rcs $(NAME) $(OFILES) 
	@echo "** $(ANSI_GREEN)LIBFT Compiled$(ANSI_RESET) ✅ **"
 
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
