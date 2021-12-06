# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 19:37:01 by hakim             #+#    #+#              #
#    Updated: 2021/12/06 23:30:41 by hakim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	ft_printf.c 
#SRC_BONUS = 
OBJ = $(SRC:.c=.o)
#OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = libftprintf.a

#ifdef BONUS
#	OBJS = $(OBJ) $(OBJ_BONUS)
#else
#	OBJS = $(OBJ)
#endif

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

#bonus:
#	@make BONUS=1 all

clean:
	rm -f $(OBJ) #$(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all clean re bonus
