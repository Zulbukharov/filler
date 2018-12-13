/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:38:11 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/12 20:22:36 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	draw_elem_rect(t_global *global, int x, int y)
{
	if (global->map[x][y] == 'X' || global->map[x][y] == 'O' ||
	global->map[x][y] == 'x' || global->map[x][y] == 'o')
	{
		if (global->map[x][y] == 'x' || global->map[x][y] == 'X')
		{
			global->score_p2 = global->clear ? global->score_p2 + 1 :
			global->score_p2;
			SDL_RenderCopy(global->renderer, global->texture[0], NULL,
				&(SDL_Rect){x * global->elem_size_x + 400, y *
		global->elem_size_y + 50, global->elem_size_x, global->elem_size_y});
		}
		else
		{
			global->score_p1 = global->clear ? global->score_p1 + 1 :
			global->score_p1;
			SDL_RenderCopy(global->renderer, global->texture[1], NULL,
			&(SDL_Rect){x * global->elem_size_x + 400, y *
		global->elem_size_y + 50, global->elem_size_x, global->elem_size_y});
		}
	}
}

void	redraw2(t_global *global, t_util *u)
{
	if (!global->iter)
	{
		global->x_h = ft_atoi(&global->line[u->i]);
		global->y_w = ft_atoi(&global->line[u->i +
			ft_get_int_len(global->x_h)]);
		global->elem_size_x = (WIN_X - FRAME_SIZE) / global->x_h;
		global->elem_size_y = (WIN_Y - FRAME_SIZE_Y) / global->y_w;
		global->map = (char**)malloc(sizeof(char*) * global->x_h);
		u->x = 0;
		while (u->x < global->x_h)
		{
			global->map[u->x] = (char*)malloc(sizeof(char) * global->y_w);
			u->x++;
		}
		global->iter = 1;
	}
}

void	redraw3(t_global *global, t_util *u)
{
	free(global->line);
	global->line = NULL;
	u->x = 0;
	ft_get_next_line(0, &global->line);
	free(global->line);
	global->line = NULL;
	while (u->x < global->x_h)
	{
		u->i = 0;
		ft_get_next_line(0, &global->line);
		u->old = global->line;
		while (ft_isnum(*global->line) == 1 || *global->line == ' ')
			global->line++;
		while (u->i < global->y_w)
		{
			global->map[u->x][u->i] = global->line[u->i];
			u->i++;
		}
		u->x++;
		free(u->old);
		global->line = NULL;
		u->old = NULL;
	}
}

void	redraw(t_global *global)
{
	t_util u;

	u = (t_util){0, 0, 0};
	global->line = NULL;
	while (1)
	{
		if (ft_get_next_line(0, &global->line) <= 0)
		{
			global->clear = 0;
			return ;
		}
		if (ft_strncmp("Plateau", global->line, 7) == 0)
		{
			break ;
		}
		free(global->line);
	}
	while (ft_isnum(global->line[u.i]) == 0)
		u.i++;
	redraw2(global, &u);
	redraw3(global, &u);
}

void	event(t_global *global)
{
	if (global->event.type == SDL_QUIT)
		global->done = SDL_TRUE;
	if (global->event.key.keysym.sym == SDLK_ESCAPE)
		global->done = SDL_TRUE;
}
