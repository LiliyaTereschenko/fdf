# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkihn <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 11:56:12 by kkihn             #+#    #+#              #
#    Updated: 2018/12/13 14:44:38 by kkihn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = fdf
LIBS = -L /usr/local/lib -lm -framework OpenGL -framework AppKit -L /usr/local/lib -lmlx

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -o $(NAME) *.c  $(FLAGS) $(LIBS) libft/libft.a
	
	

clean:
	rm -f *.o
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
