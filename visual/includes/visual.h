/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:05:37 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/12 00:11:35 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# include <libft.h>
# include <ft_printf.h>
# include <time.h>

# define WIN_X 1200
# define WIN_Y 1200
# define FRAME_SIZE 300

typedef struct		s_cord
{
	int				x;
	int				y;
}					t_cord;

typedef	struct		s_util
{
	int				i;
	int				x;
	char			*old;
}					t_util;

typedef	struct		s_global
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture[4];
	SDL_Texture		*frame;
	TTF_Font		*font;
	SDL_bool		done;
	SDL_Event		event;
	int				first_read;
	int				x_h;
	int				y_w;
	int				token_h;
	int				token_w;
	char			*line;
	char			**map;
	int				first_hit;
	int				sum_of_hit;
	int				elem_size_x;
	int				elem_size_y;
	int				clear;
	int				score_p1;
	int				score_p2;
	SDL_Texture		*elf;
}					t_global;

#endif
