# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlavinia <nlavinia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 07:09:32 by nlavinia          #+#    #+#              #
#    Updated: 2022/07/07 13:02:35 by nlavinia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	libftprintf.a

SRC 	= 	ft_printf.c \
			src.c \
			src1.c

SRC_B 	= 	ft_printf_bonus.c \
			ft_printf_hexa_p_bonus.c \
			ft_printf_num_s_bonus.c \
			ft_printf_util_bonus.c \
			ft_printf_wid_prec_bonus.c \
			ft_printf_util1_bonus.c

OBJ = $(SRC:.c=.o)

OBONUS = $(SRC_B:.c=.o)

OBJ_B = $(OBONUS)

HEADER = ft_printf.h

HEADERB = ft_printf_bonus.h

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ_B) $(HEADERB)
	ar rcs $(NAME) $(OBJ_B)

%.o : %.c
	gcc $(FLAGS) $< -c

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
