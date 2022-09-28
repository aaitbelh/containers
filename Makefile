# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 11:27:33 by aaitbelh          #+#    #+#              #
#    Updated: 2022/09/09 11:37:40 by aaitbelh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = container
SRC = vector.cpp
OBJS = $(SRC:.cpp=.o)
CC = c++ -Wall -Werror -Wextra -std=c++98

all : $(NAME)
$(NAME) :$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o:%.cpp
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all