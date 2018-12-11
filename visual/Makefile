# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/09 22:04:58 by azulbukh          #+#    #+#              #
#    Updated: 2018/12/12 00:10:43 by azulbukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visual

SRC = visual.c

OBJECT_VISUAL = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
INCLUDES_VISUAL = -I ./includes/
INCLUDES_LIBFT = -I ./../src/includes
LIBFT = ./../src/libftprintf.a
FRAMEWORK_SDL2 = -F ./src/SDL -framework SDL2 \
	-framework SDL2_image \
	-framework SDL2_ttf \
	-framework SDL2_mixer
INCLUDES_SDL2 = -I ./src/SDL/SDL2.framework/Headers
INCLUDES_SDL2_IMAGE = -I ./src/SDL/SDL2_image.framework/Headers
INCLUDES_SDL2_MIXER = -I ./src/SDL/SDL2_mixer.framework/Headers
INCLUDES_SDL2_TTF = -I ./src/SDL/SDL2_ttf.framework/Headers

all: $(NAME)

$(NAME) : $(OBJECT_VISUAL)
	# make -C ./src
	# @echo "\033[0;32m[LIB COMPILED]\033[0;0m"
	@gcc -o $(NAME) $(FLAGS) $(OBJECT_VISUAL) $(LIBFT) $(INCLUDES_SDL2) $(INCLUDES_SDL2_IMAGE) -rpath @loader_path/src/sdl $(FRAMEWORK_SDL2) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)
	@echo "\033[0;32m[VISUAL COMPILED]\033[0;0m"

%.o: %.c includes/*.h
	gcc -g $(FLAGS) -o $@ -c $< $(INCLUDES_VISUAL) $(INCLUDES_LIBFT) $(INCLUDES_SDL2) $(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

%.o: %.c
	gcc	-g $(FLAGS) -o $@ -c $< $(INCLUDES_VISUAL) $(INCLUDES_LIBFT) $(INCLUDES_SDL2) $(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

clean:
	# make -C ./src clean
	/bin/rm -f $(OBJECT_VISUAL)
	rm -f TAGS

fclean: clean
	# /bin/rm -f ./src/libftprintf.a
	/bin/rm -f $(NAME)

re: fclean all tags

tags:
	etags -R *.c includes/*.h
