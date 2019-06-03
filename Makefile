# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkroeke <dkroeke@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/04 15:51:09 by euan           #+#    #+#                 #
#    Updated: 2019/05/11 13:04:11 by ehollidg      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = main converter checker clear_array free_ret print_fillit solver \
	  create_map atl fill_tetro remove_tetro check_tetros del_tet
SRCF = $(SRC:%=srcs/%.c)
OBJ = $(SRC:%=%.o)
NAME = fillit

all: $(NAME)

$(NAME): $(SRCF)
	make -C libft/ fclean && make -C libft/
	clang -Wall -Werror -Wextra -I libft -c $(SRCF)
	clang -o $(NAME) $(OBJ) -I libft -L libft -lft

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
