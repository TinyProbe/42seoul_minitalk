# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:35:02 by tkong             #+#    #+#              #
#    Updated: 2022/09/21 15:35:05 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk
NAME1		= server
NAME2		= client
BONUS		= minitalk_bonus
BONUS1		= server_bonus
BONUS2		= client_bonus
CC			= cc
CFLAG		= -Wall -Wextra -Werror
SRC_MS		= server.c		\
			  handler.c		\

SRC_MC		= client.c		\
			  send.c		\

SRC_BS		= 			\

SRC_BC		= 			\

LIB			= libft/libft.a
RM			= rm -f

$(NAME) :	$(NAME1) $(NAME2)

$(NAME1) :	$(LIB) $(SRC_MS)
	$(CC) $(SRC_MS) $(LIB) -o $(NAME1)

$(NAME2) :	$(LIB) $(SRC_MC)
	$(CC) $(SRC_MC) $(LIB) -o $(NAME2)

$(BONUS) :	$(BONUS1) $(BONUS2)

$(BONUS1) :	$(LIB) $(SRC_BS)
	$(CC) $(SRC_BS) $(LIB) -o $(BONUS1)

$(BONUS2) :	$(LIB) $(SRC_BC)
	$(CC) $(SRC_BC) $(LIB) -o $(BONUS2)

$(LIB) :
	make -C ./libft B=1 all

all :		$(NAME)

bonus :		$(BONUS)

clean :
	make -C ./libft clean

fclean :	clean
	$(RM) $(LIB) $(NAME1) $(NAME2) $(BONUS1) $(BONUS2)

re :		fclean all

.PHONY :	all bonus clean fclean re
