# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/21 14:53:46 by bhamidi           #+#    #+#              #
#    Updated: 2018/06/06 18:05:34 by bhamidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX				= g++
NAME			= glfw.so
CXXFLAGS		= -Werror -Wextra -Wall -std=c++11 -O2 -Wno-deprecated
LIBFLAGS 		= -I ~/.brew/include -L ~/.brew/lib -lglfw -framework opengl 
INCLUDES_PATH 	= -I ~/.brew/include -I./../includes

OBJ = Glfw.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -shared -fPIC -o $@ $(LIBFLAGS)

%.o: %.cpp Makefile Glfw.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES_PATH) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)


re : fclean all

.PHONY: all fclean clean re
