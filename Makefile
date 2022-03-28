# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 11:24:13 by asfaihi           #+#    #+#              #
#    Updated: 2022/03/28 13:39:10 by asfaihi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRC = main.cpp 

OBJECT = $(SRC:%.cpp=%.o)

FLAGS = -Wall -Wextra -Werror

CPP_STANDARD = -std=c++98

VEC_HEADERS = vector/utils.hpp vector/iterator.hpp vector/vector.hpp
STACK_HEADERS = stack/stack.hpp
MAP_HEADERS = map/utils.hpp map/iterator.hpp map/tree.hpp map/map.hpp

all: $(NAME)

$(NAME): $(OBJECT)
	clang++ $(OBJECT) -o $(NAME)

%.o:%.cpp $(VEC_HEADERS) $(STACK_HEADERS) $(MAP_HEADERS)
	clang++ $(FLAGS) $(CPP_STANDARD) -c $<

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
