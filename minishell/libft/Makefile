# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbungo <wbungo@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 16:42:24 by wbungo            #+#    #+#              #
#    Updated: 2022/10/18 16:30:19 by wbungo           ###   ########.fr        #
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

#SHELL=/bin/bash
#UNAME = $(shell uname -s)
#PRINTF = echo
#ifeq ($(UNAME), Linux)
#	PRINTF = echo -e
#endif

# Make variables
PRINTF = LC_NUMERIC="en_US.UTF-8" printf
CC = gcc -MD
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = libft.h
SRC_DIR = src
SRCB_DIR = srcb
SRCA_DIR = srca
OBJ_DIR = obj
OBJB_DIR = objb
OBJA_DIR = obja
BIN_DIR = bin
BIN = libft.a
NAME = $(BIN_DIR)/$(BIN)

SRC =	ft_atoi.c ft_bzero.c		\
	ft_calloc.c ft_putendl_fd.c		\
	ft_itoa.c ft_putchar_fd.c		\
	ft_putstr_fd.c ft_memccpy.c		\
	ft_memchr.c ft_memcmp.c			\
	ft_memcpy.c ft_isalnum.c		\
	ft_isalpha.c ft_isascii.c		\
	ft_isdigit.c ft_isprint.c		\
	ft_memmove.c ft_memset.c		\
	ft_split.c ft_strchr.c			\
	ft_strdup.c ft_strjoin.c		\
	ft_strlcat.c ft_strlcpy.c		\
	ft_strlen.c ft_strmapi.c		\
	ft_strncmp.c ft_strnstr.c		\
	ft_strrchr.c ft_strtrim.c		\
	ft_substr.c ft_tolower.c		\
	ft_toupper.c ft_putnbr_fd.c		\

SRCB = ft_lstadd_back.c	\
	ft_lstadd_front.c	\
	ft_lstclear.c		\
	ft_lstdelone.c		\
	ft_lstiter.c		\
	ft_lstlast.c		\
	ft_lstsize.c		\
	ft_lstnew.c			\
	ft_lstmap.c			\
	ft_lstget_at.c

SRCA = ft_putnbr_base_fd.c ft_putstrn_fd.c		\
	ft_putnchar_fd.c ft_isspace.c ft_uitoa.c	\
	ft_nbrlen.c ft_strrncmp.c ft_countchar.c	\
	ft_strenlarge.c ft_recursive_power.c		\
	ft_chartostr.c ft_sqrt.c ft_newvector.c		\
	ft_euclideandistance.c  ft_atoi2.c			\
	ft_free_matrix.c ft_dup_matrix.c			\
	ft_strchr_i.c ft_putmatrix_fd.c				\
	ft_matrixlen.c ft_strchars_i.c				\
	ft_between_chars.c ft_subsplit.c			\
	ft_extend_matrix.c ft_matrixtolst.c			\
	ft_lsttomatrix.c ft_matrix_replace_in.c		\
	ft_declare_matrix.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJB = $(addprefix $(OBJB_DIR)/, $(SRCB:.c=.o))

OBJA = $(addprefix $(OBJA_DIR)/, $(SRCA:.c=.o))

all: $(NAME)

$(NAME): create_dirs $(OBJ) bonus additional
	@$(PRINTF) "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(PRINTF) "$(GREEN)•$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: create_dirs $(OBJ) $(OBJB)
	@$(AR) $(NAME) $(OBJ) $(OBJB)

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c
	@$(PRINTF) "$(GREEN)•$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

additional: create_dirs $(OBJA)
	@$(AR) $(NAME) $(OBJA)

$(OBJA_DIR)/%.o: $(SRCA_DIR)/%.c
	@$(PRINTF) "$(GREEN)•$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files in libft...$(DEFAULT)\n"
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJB_DIR)
	@$(RM) -r $(OBJA_DIR)

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJB_DIR)
	@mkdir -p $(OBJA_DIR)
	@mkdir -p $(BIN_DIR)

norminette:
	@$(PRINTF) "$(CYAN)\nChecking norm for libft...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(SRCB_DIR) $(SRCA_DIR) inc/libft.h

re: fclean
	@make all

git:
	git add .
	git commit
	git push

-include $(OBJ_DIR)/*.d
-include $(OBJB_DIR)/*.d
-include $(OBJA_DIR)/*.d

.PHONY: all bonus additional clean fclean git norminette create_dirs re 
