/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:05:07 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/12 20:19:16 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	put_text(t_global *global, char *s, t_cord d, int i)
{
	SDL_Surface *text_sur;
	SDL_Texture *text;

	text_sur = TTF_RenderText_Solid(global->font, s,
		(SDL_Color){255, 255, 255, 255});
	text = SDL_CreateTextureFromSurface(global->renderer, text_sur);
	SDL_FreeSurface(text_sur);
	if (i > 0)
		SDL_RenderCopy(global->renderer, text, NULL,
			&(SDL_Rect){d.x - (ft_strlen(s) * 18) - 10,
			d.y, text_sur->w, text_sur->h});
	else
		SDL_RenderCopy(global->renderer, text, NULL,
		&(SDL_Rect){d.x, d.y, text_sur->w, text_sur->h});
	SDL_DestroyTexture(text);
	if (s)
		free(s);
}

void	loop_for_map(t_global *global)
{
	t_cord d;

	d = (t_cord){0, 0};
	SDL_RenderCopy(global->renderer, global->elf, NULL,
		&(SDL_Rect){0, 0, WIN_X, WIN_Y});
	global->score_p1 = global->clear ? 0 : global->score_p1;
	global->score_p2 = global->clear ? 0 : global->score_p2;
	while (d.x < global->x_h)
	{
		d.y = 0;
		while (d.y < global->y_w)
		{
			draw_elem_rect(global, d.x, d.y);
			d.y++;
		}
		d.x++;
	}
	put_text(global, ft_strdup("Player 2 BLUE"), (t_cord){400, 50}, 1);
	put_text(global, ft_itoa_base(global->score_p2, 10), (t_cord){400, 100}, 1);
	put_text(global, ft_itoa_base(global->score_p1, 10),
		(t_cord){1510, 100}, 0);
	put_text(global, ft_strdup("RED Player 1"), (t_cord){1510, 50}, 0);
}

void	loop(t_global global)
{
	clock_t			t1;
	clock_t			t2;

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
			draw_grid(&global);
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
	global->texture[0] = IMG_LoadTexture(global->renderer, "1.jpg");
	global->texture[1] = IMG_LoadTexture(global->renderer, "2.jpg");
	global->elf = IMG_LoadTexture(global->renderer, "back.png");
	global->done = SDL_FALSE;
}

int		main(void)
{
	t_global global;

	global = (t_global){0, 0, {0, 0}, 0, 0, 0, {0},
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
	if (SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		init_sdl(&global);
		loop(global);
		destroy(&global);
		if (global.renderer)
			SDL_DestroyRenderer(global.renderer);
		if (global.window)
			SDL_DestroyWindow(global.window);
	}
	TTF_Quit();
	SDL_Quit();
	return (0);
}
