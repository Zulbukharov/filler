/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:05:07 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/12 00:11:43 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	destroy(t_global *global)
{
	t_cord dot;

	dot = (t_cord){0, 0};
	while (dot.x < global->x_h)
	{
		free(global->map[dot.x]);
		global->map[dot.x] = NULL;
		dot.x++;
	}
	dot.x = 0;
	free(global->map);
	global->map = NULL;
}

void	draw_elem_rect(t_global *global, int x, int y)
{
	if (global->map[x][y] == 'X' || global->map[x][y] == 'O' ||
	global->map[x][y] == 'x' || global->map[x][y] == 'o')
	{
		SDL_Rect rect = {x * global->elem_size_x, y * global->elem_size_y, global->elem_size_x, global->elem_size_y};
		if (global->map[x][y] == 'x' || global->map[x][y] == 'X')
		{
			global->score_p2 = global->clear ? global->score_p2 + 1 : global->score_p2;
			SDL_RenderCopy(global->renderer, global->texture[0], NULL, &rect);
		}
		else
		{
			global->score_p1 = global->clear ? global->score_p1 + 1 : global->score_p1;
			SDL_RenderCopy(global->renderer, global->texture[1], NULL, &rect);
		}
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
	while(ft_isnum(global->line[u.i]) == 0)
		u.i++;
	global->x_h = ft_atoi(&global->line[u.i]);
	global->y_w = ft_atoi(&global->line[u.i + ft_get_int_len(global->x_h)]);
	global->elem_size_x = WIN_X / global->x_h;
	global->elem_size_y = (WIN_Y - FRAME_SIZE) / global->y_w;
	global->map = (char**)malloc(sizeof(char*) * global->x_h);
	u.x = 0;
	while (u.x < global->x_h)
	{
		global->map[u.x] = (char*)malloc(sizeof(char) * global->y_w);
		u.x++;
	}
	free(global->line);
	global->line = NULL;
	u.x = 0;
	ft_get_next_line(0, &global->line);
	free(global->line);
	global->line = NULL;
	while (u.x < global->x_h)
	{
		u.i = 0;
		ft_get_next_line(0, &global->line);
		u.old = global->line;
		while (ft_isnum(*global->line) == 1 || *global->line == ' ')
			global->line++;
		while (u.i < global->y_w)
		{
			global->map[u.x][u.i] = global->line[u.i];
			u.i++;
		}
		u.x++;
		free(u.old);
		global->line = NULL;
		u.old = NULL;
	}
}

void			event(t_global *global)
{
	if (global->event.type == SDL_QUIT)
		global->done = SDL_TRUE;
	if (global->event.key.keysym.sym == SDLK_ESCAPE)
		global->done = SDL_TRUE;
}

void			put_text(t_global *global, char *s, int x, int y)
{
	SDL_Color textColor = { 0, 0, 0, 0 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(global->font, s, textColor);
	SDL_Texture* text = SDL_CreateTextureFromSurface(global->renderer, textSurface);
	int text_width = textSurface->w;
	int text_height = textSurface->h;
	SDL_FreeSurface(textSurface);
	SDL_Rect renderQuad = {x, y, text_width, text_height};
	SDL_RenderCopy(global->renderer, text, NULL, &renderQuad);
	SDL_DestroyTexture(text);
	if (s)
		free(s);
}

void			loop_for_map(t_global *global)
{
	global->score_p1 = global->clear ? 0 : global->score_p1;
	global->score_p2 = global->clear ? 0 : global->score_p2;
	for (int x = 0; x < global->x_h; x++)
		for (int y = 0; y < global->y_w; y++)
			draw_elem_rect(global, x, y);
	destroy(global);
	SDL_Rect rect3 = {0, WIN_Y - FRAME_SIZE, WIN_X, FRAME_SIZE};
	SDL_RenderCopy(global->renderer, global->frame, NULL, &rect3);
	SDL_Rect rect = {200, WIN_Y - FRAME_SIZE + 20, 200, 200};
	SDL_RenderCopy(global->renderer, global->texture[2], NULL, &rect);
	SDL_Rect rect1 = {800, WIN_Y - FRAME_SIZE + 20, 200, 200};
	SDL_RenderCopy(global->renderer, global->texture[3], NULL, &rect1);
	put_text(global, ft_itoa_base(global->score_p1, 10), 280, WIN_Y - FRAME_SIZE + 230);
	put_text(global, ft_itoa_base(global->score_p2, 10), 880, WIN_Y - FRAME_SIZE + 230);
}

void			loop(t_global global)
{
	clock_t			t1, t2;

	t2 = clock() / 50000;
	while (!global.done)
	{
		t1 = clock() / 50000;
		if (t1 > t2)
		{
			SDL_SetRenderDrawColor(global.renderer, 255, 255, 255, 255);
			SDL_RenderClear(global.renderer);
			while (SDL_PollEvent(&global.event))
				event(&global);
			if (global.clear)
				redraw(&global);
			loop_for_map(&global);
			SDL_RenderPresent(global.renderer);
		}
	}
}

void	init_sdl(t_global *global)
{
	global->window = SDL_CreateWindow("FILLER",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	WIN_X, WIN_Y, SDL_WINDOW_SHOWN);
	global->renderer = SDL_CreateRenderer(global->window,
		-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	TTF_Init();
	if (!(global->font = TTF_OpenFont("font.ttf", 48)))
		perror(TTF_GetError());
	if (!(global->frame = IMG_LoadTexture(global->renderer, "art.jpg")))
		perror("[Error]\n");
	global->texture[0] = IMG_LoadTexture(global->renderer, "1.jpg");
	global->texture[1] = IMG_LoadTexture(global->renderer, "2.jpg");
	global->texture[2] = IMG_LoadTexture(global->renderer, "red.png");
	global->texture[3] = IMG_LoadTexture(global->renderer, "blue.png");
	global->elf = IMG_LoadTexture(global->renderer, "elf.png");
	global->done = SDL_FALSE;
	ft_putstr_fd("init\n", 2);
}

int		main(void)
{
	t_global global;

	global = (t_global){0, 0, {}, 0, 0, 0, {}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
	if (SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		init_sdl(&global);
		loop(global);
		if (global.renderer)
			SDL_DestroyRenderer(global.renderer);
		if (global.window)
			SDL_DestroyWindow(global.window);
	}
	TTF_Quit();
	SDL_Quit();
	return (0);
}
