# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/09 13:37:15 by azulbukh          #+#    #+#              #
#    Updated: 2018/12/12 20:31:38 by azulbukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = azulbukh.filler

SRC = filler.c algo.c parse.c

OBJECT_FILLER = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
INCLUDES_FILLER = -I ./includes/
INCLUDES_LIBFT = -I ./src/includes
LIBFT = ./src/libftprintf.a

all: $(NAME)

$(NAME) : $(OBJECT_FILLER)
	make -C ./src
	make -C ./visual
	@echo "\033[0;32m[LIB COMPILED]\033[0;0m"
	@gcc -o $(NAME) $(FLAGS) $(LIBFT) $(OBJECT_FILLER)
	@echo "\033[0;32m[FILLER BOT COMPILED]\033[0;0m"

%.o: %.c includes/*.h
	gcc -g $(FLAGS) -o $@ -c $< $(INCLUDES_FILLER) $(INCLUDES_LIBFT)

%.o: %.c
	gcc	-g $(FLAGS) -o $@ -c $< $(INCLUDES_FILLER) $(INCLUDES_LIBFT)

clean:
	make -C ./src clean
	make -C ./visual clean
	/bin/rm -f $(OBJECT_FILLER)
	rm -f TAGS

fclean: clean
	/bin/rm -f ./src/libftprintf.a
	make -C ./visual fclean
	/bin/rm -f $(NAME)

re: fclean all tags

tags:
	etags -R *.c includes/*.h
