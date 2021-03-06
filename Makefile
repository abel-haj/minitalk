# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 20:55:20 by abel-haj          #+#    #+#              #
#    Updated: 2021/06/20 12:41:43 by abel-haj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

SRC			= utils.c

CFLAGS		= -Wall -Werror -Wextra
LEAKS		= -fsanitize=address

SERVER		= server

CLIENT		= client

$(NAME)		: $(SERVER) $(CLIENT)

$(SERVER)	:
	@gcc $(CFLAGS) $(LEAKS) receiver.c $(SRC) -o $(SERVER) && echo "Plugging things..."

$(CLIENT)	:
	@gcc $(CFLAGS) $(LEAKS) sender.c $(SRC) -o $(CLIENT) && echo "Connecting to network..."

all			: $(SERVER) $(CLIENT)
a				: all

bonus		: 
	@echo ":)"

clean		: 
	rm -rf a.out .vscode a.out.DSYM *.o
c				: clean

fclean	: clean
	rm -f $(SERVER) $(CLIENT)
f				: fclean

re			: fclean all
