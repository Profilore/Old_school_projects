# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbungo <wbungo@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 16:42:24 by wbungo            #+#    #+#              #
#    Updated: 2022/10/18 17:50:37 by wbungo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Make variables
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -MD -g3 
RM = rm -f
CC = gcc
PRINTF = LC_NUMERIC="en_US.UTF-8" printf
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIBFT = libft/bin/libft.a
BIN = minishell
NAME = $(BIN_DIR)/$(BIN)
#RLINC1 = -I /usr/local/opt/readline/include
RLINC2 = -I/usr/local/Cellar/readline/8.1.2/include
#RLLIB1 = -L /usr/local/opt/readline/lib
RLLIB2 = -L/usr/local/Cellar/readline/8.1.2/lib

SRC = main.c builtins.c ft_strtrim_all.c exec.c			\
	  fill_node.c get_params.c ft_cmdtrim.c utils.c		\
	  expand.c heredoc.c error.c env.c custom_cmd.c		\
	  get_next_line.c get_next_line_utils.c				\
	  ft_cmdsubsplit.c signal.c minishell.c get_cmd.c	\

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_LFT = $(addprefix $(OBJ_LFT_DIR)/, $(SRC_LFT:.c=.o))

all: $(NAME)

$(NAME): create_dirs compile_libft $(OBJ)
	@$(CC) $(RLLIB1) $(RLLIB2) $(RLINC1) $(RLINC2) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -o $@
	@$(PRINTF) "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(PRINTF) "$(GREEN)•$(DEFAULT)"
	@$(CC) $(RLINC1) $(RLINC2) $(CFLAGS) $(CDEBUG) -c $< -o $@

compile_libft:
	@make -C libft

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files in $(BIN)...$(DEFAULT)\n"
	@if [ -d "libft" ]; then \
		make clean -C libft/; \
	fi
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@$(PRINTF) "$(CYAN)Removed $(BIN)$(DEFAULT)\n"

norminette:
	@if [ -d "libft" ]; then \
		make norminette -C libft/; \
	fi
	@$(PRINTF) "$(CYAN)\nChecking norm for $(BIN)...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) inc/

re: fclean
	@make all

git:
	git add .
	git commit
	git push

-include $(OBJ_DIR)/*.d
-include $(OBJB_DIR)/*.d

.PHONY: all clean fclean norminette create_dirs re
