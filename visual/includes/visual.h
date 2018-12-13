/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:05:37 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/12 20:19:29 by azulbukh         ###   ########.fr       */
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

# define WIN_X 1900
# define WIN_Y 1000
# define FRAME_SIZE 800
# define FRAME_SIZE_Y 100

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
	SDL_Texture		*texture[2];
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
	int				iter;
}					t_global;

void				draw_grid(t_global *g);
void				destroy(t_global *global);
void				draw_elem_rect(t_global *global, int x, int y);
void				redraw2(t_global *global, t_util *u);
void				redraw3(t_global *global, t_util *u);
void				redraw(t_global *global);
void				event(t_global *global);
void				put_text(t_global *global, char *s, t_cord d, int i);
void				loop_for_map(t_global *global);
void				loop(t_global global);
void				init_sdl(t_global *global);

#endif
