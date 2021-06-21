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

SRC			= utils.c

CFLAGS		= -Wall -Werror -Wextra

SERVER		= server

CLIENT		= client

$(SERVER)	:
	@gcc $(CFLAGS) receiver.c $(SRC) -o $(SERVER) && echo "Plugging things..."

$(CLIENT)	:
	@gcc $(CFLAGS) sender.c $(SRC) -o $(CLIENT) && echo "Connecting to network..."

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
