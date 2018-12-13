/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:37:48 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/12 19:37:55 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	draw_grid(t_global *g)
{
	t_cord d;

	d = (t_cord){0, 0};
	SDL_SetRenderDrawColor(g->renderer, 0, 0, 0, 255);
	while (d.x < g->x_h)
	{
		d.y = 0;
		while (d.y < g->y_w)
		{
			SDL_RenderDrawLine(g->renderer, d.x * g->elem_size_x + 400,
			d.y * g->elem_size_y + 50, d.x * g->elem_size_x + 400, d.y *
			g->elem_size_y + 50 + g->elem_size_y);
			SDL_RenderDrawLine(g->renderer, d.x * g->elem_size_x + 400,
			d.y * g->elem_size_y + 50, d.x * g->elem_size_x + 400 +
			g->elem_size_x, d.y * g->elem_size_y + 50);
			d.y++;
		}
		d.x++;
	}
	SDL_RenderDrawLine(g->renderer, g->x_h *
	g->elem_size_x + 400, g->y_w * g->elem_size_y + 50,
	g->x_h * g->elem_size_x + 400, FRAME_SIZE_Y - 50);
	SDL_RenderDrawLine(g->renderer, g->x_h * g->elem_size_x +
	400, g->y_w * g->elem_size_y + 50, FRAME_SIZE - 400, g->y_w
	* g->elem_size_y + 50);
}

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
