# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 11:24:13 by asfaihi           #+#    #+#              #
#    Updated: 2021/12/13 11:24:33 by asfaihi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRC = main.cpp 

OBJECT = $(SRC:%.cpp=%.o)

FLAGS = -Wall -Wextra -Werror

CPP_STANDARD = -std=c++98

VEC_HEADERS = vector.hpp vectorIt.hpp vectorRevIt.hpp
STACK_HEADERS = stack.hpp
MAP_HEADERS = map.hpp mapIt.hpp mapRevIt.hpp redBlackTree.hpp


all: $(NAME)

$(NAME): $(OBJECT)
	clang++ $(OBJECT) -o $(NAME)

%.o:%.cpp $(VEC_HEADERS) $(STACK_HEADERS) $(MAP_HEADERS)
	clang++ -c $<

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
