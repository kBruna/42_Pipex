#---- Colors -----

C_BLUE	= \033[0;34
C_GREEN	= \033[0;32
C_RED	= \033[0;31
C_END	= \033[0m


# ---- File Vars -----

NAME	= pipex
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
C_TEST	= -g3

SRCS_FILES	= main.c
SRCS	= src/$(SRCS_FILES)
OBJS	= $(SRCS:.c=.o)

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
	$(CC) $(CFLAGS) $(C_TEST) $(OBJS) -L$(DIR_LIBFT) -lft -o $@
	@echo "\n$(C_BLUE);1m\t-> $(NAME) compiled successfully!$(C_END)\n"

mem: $(NAME)
	$(shell valgrind	--leak-check=full \
				--show-leak-kinds=all	\
				--track-fds=yes			\
				--trace-children=yes	\
				--track-origins=yes ./pipex $(ARGS))

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(C_BLUE);m\t-> $@ compiled\n$(C_END)"

$(LIBFT) :
	@$(MAKE) -sC $(DIR_LIBFT) all
	@echo "\n$(C_BLUE)m\t-> $@ compiled$(C_END)\n"


# ----- Clean -----
	
clean:
	@$(MAKE) -sC $(DIR_LIBFT) $@
	@rm -fr $(OBJS)
	@echo "\n$(C_RED)m\t-> OBJs Deleted$(C_END)"

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -sC $(DIR_LIBFT) $@
	@echo "\n$(C_RED)m\t-> Files Deleted$(C_END)"

re : fclean all

.PHONY: all clean fclean re val mem
