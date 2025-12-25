# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: buehara <buehara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 12:44:47 by buehara           #+#    #+#              #
#    Updated: 2025/12/22 12:27:07 by buehara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -Iincludes


AR = ar

RCS = rcs

CC = cc

OBJ_DIR = obj

SRC_DIR = src

C_FILES = \
	ft_atoi.c	\
	ft_bzero.c	\
	ft_calloc.c	\
	ft_itoa.c	\
	ft_isalnum.c	\
	ft_isalpha.c	\
	ft_isascii.c	\
	ft_isdigit.c	\
	ft_isprint.c	\
	ft_memchr.c	\
	ft_memcmp.c	\
	ft_memcpy.c	\
	ft_memset.c	\
	ft_memmove.c	\
	ft_putchar_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\
	ft_putstr_fd.c	\
	ft_split.c	\
	ft_strchr.c	\
	ft_striteri.c	\
	ft_strjoin.c	\
	ft_strlen.c	\
	ft_strlcat.c	\
	ft_strlcpy.c	\
	ft_strmapi.c	\
	ft_strncmp.c	\
	ft_strdup.c	\
	ft_strnstr.c	\
	ft_strrchr.c	\
	ft_strtrim.c	\
	ft_substr.c	\
	ft_tolower.c	\
	ft_toupper.c	\
 	ft_lstnew_bonus.c		\
	ft_lstadd_front_bonus.c		\
	ft_lstsize_bonus.c		\
	ft_lstlast_bonus.c		\
	ft_lstadd_back_bonus.c		\
	ft_lstdelone_bonus.c		\
	ft_lstclear_bonus.c		\
	ft_lstiter_bonus.c		\
	ft_lstmap_bonus.c		\
	gnl/get_next_line.c		\
	gnl/get_next_line_utils.c	\
	printf/ft_printf.c


C_SOURCE = $(addprefix $(SRC_DIR)/, $(C_FILES))


OBJ = $(C_SOURCE:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)



all: $(NAME)


$(NAME) : $(OBJ) 
	@$(AR) $(RCS) $(NAME) $(OBJ)


$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir $(OBJ_DIR)/gnl
	@mkdir $(OBJ_DIR)/printf

clean:
	@rm -fr $(OBJ_DIR)

fclean: clean
	@rm -fr $(NAME)


re: fclean all


.PHONY: all bonus clean fclean re
