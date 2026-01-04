#---- Colors -----

C_BOLD	= \033[1m
C_BLUE	= \033[0;34
C_GREEN	= \033[0;32
C_RED	= \033[0;31
C_END	= \033[0m


# ---- File Vars -----

NAME	= pipex
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
C_TEST	= -g3

SRCS_FILES	= 	\
				pipex_util.c	\
				parsing.c		\
				main.c			\

SRCS_BONUS	= 	here_doc_bonus.c	\
				pipex_bonus.c		\
				child_bonus.c		\
				lst_util_bonus.c	\
				pipex_util_bonus.c	\
				parsing_bonus.c		\
				main_bonus.c


SRCS		= $(addprefix src/, $(SRCS_FILES))
FILES_BONUS	= $(addprefix src/, $(SRCS_BONUS))
OBJS_DIR 	= obj
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.c=.o))
OBJS_BONUS	= $(addprefix src/, $(SRCS_BONUS))

DIR_LIBFT	= src/42_Libft
LIBFT		= $(DIR_LIBFT)/libft.a

ARGS ?= 

# ---- Recipes -----

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "\n$(C_GREEN);1m\t-> Compiling files...$(C_END)\n"
	$(CC) $(CFLAGS) $(OBJS) -L$(DIR_LIBFT) -lft -o $@
	@echo "\n$(C_GREEN);1m\t-> $(NAME) compiled successfully!$(C_END)\n"

val: $(LIBFT) $(OBJS)
	@echo "\n$(C_BLUE);1m\t-> Compiling with test flags\n$(C_END)"
	$(CC) $(CFLAGS) $(C_TEST) $(OBJS) -L$(DIR_LIBFT) -lft -o $(NAME)
	@echo "\n$(C_BLUE);1m\t-> $(NAME) compiled successfully!$(C_END)\n"

mem: $(NAME)
	valgrind --suppressions=pipex.supp --track-fds=yes	\
				--leak-check=full		\
				--show-leak-kinds=all	\
				--trace-children=yes	\
				--track-origins=yes 	\
				--trace-children-skip='*/bin/*,*/sbin/*,/usr/bin/*' \
				./pipex $(ARGS)

bonus: $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(DIR_LIBFT) -lft -o pipex_bonus

$(OBJS_DIR)/%.o: src/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(C_GREEN)m\t-> $(C_BOLD)[ COMPILED ] $(C_END) $(C_GREEN)m $(notdir $<)$(C_END)"

$(LIBFT) :
	@$(MAKE) -sC $(DIR_LIBFT) all
	@echo "\n$(C_BLUE)m\t-> $@ compiled$(C_END)\n"


# ----- Clean -----
	
clean:
	@$(MAKE) -sC $(DIR_LIBFT) $@
	@rm -fr $(OBJS_DIR)
	@echo "\n$(C_RED)m\t-> OBJs Deleted$(C_END)"

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -sC $(DIR_LIBFT) $@
	@echo "\n$(C_RED)m\t-> Files Deleted$(C_END)"

re : fclean all

.PHONY: all clean fclean re val mem bonus
