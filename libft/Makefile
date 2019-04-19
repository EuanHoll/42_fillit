# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkroeke <dkroeke@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/21 14:11:35 by dkroeke        #+#    #+#                 #
#    Updated: 2019/04/18 17:45:07 by dkroeke       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SOURCE = putchar putstr strcmp strlen swap atoi bzero isalnum isalpha isascii \
		isdigit isprint memalloc memcpy memset putchar_fd putendl putendl_fd  \
		putstr_fd putnbr putnbr_fd strcat strcpy strdup strrev strstr tolower \
		toupper isspace strncpy strncat strlcat strchr strrchr strnstr strncmp\
		memcmp memccpy memmove memchr memdel strnew strdel strclr striter     \
		striteri strmap strmapi strequ strnequ strsub strjoin intlen itoa     \
		isblank strtrim strsplit lstnew lstdelone lstdel lstadd lstiter lstmap \
		strcw strlend create_tda getline lstcnt lstaddend
SOURCE := $(SOURCE:%=ft_%.c)
OBJECTS := $(SOURCE:%.c=%.o)
NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SOURCE)
	ar -rcsv $(NAME) $(OBJECTS)
 
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
