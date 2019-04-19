# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ehollidg <ehollidg@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/04 15:51:09 by euan           #+#    #+#                 #
#    Updated: 2019/04/19 12:09:34 by ehollidg      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = main converter checker clear_array free_ret print_fillit solver \
	  create_map
SRCF = $(SRC:%=%.c)
OBJ = $(SRCF:%.c=%.o)
NAME = a.out

all: $(NAME)

$(NAME):
	make -C ../libft/ fclean && make -C ../libft/
	clang -Wall -Werror -Wextra -I ../libft -c $(SRCF)
	clang -o $(NAME) $(OBJ) -I ../libft -L ../libft -lft -g

clean:
	make -C ../libft/ clean
	rm -f $(OBJ) fillit.gch

fclean: clean
	make -C ../libft/ fclean
	rm -f $(NAME)

re: fclean all
