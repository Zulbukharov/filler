/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:31:49 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/12 19:32:01 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	distanse(t_filler *filler, int x, int y)
{
	t_cord	dot;
	int		s;

	s = 0;
	dot = (t_cord){0, 0};
	while (dot.x < filler->x_h)
	{
		dot.y = 0;
		while (dot.y < filler->y_w)
		{
			if (filler->map[dot.x][dot.y] == filler->enemy ||
				filler->map[dot.x][dot.y] == (filler->enemy + 32))
			{
				s = (ABS(dot.x - x)) + (ABS(dot.y - y));
				if (filler->first_hit)
					filler->hit_map[dot.x][dot.y] = s;
				filler->hit_map[dot.x][dot.y] = s <
					filler->hit_map[dot.x][dot.y] ?
					s : filler->hit_map[dot.x][dot.y];
			}
			dot.y++;
		}
		dot.x++;
	}
	filler->first_hit = 0;
}

void	loop_for_distance(t_filler *filler, t_cord *dot)
{
	while (dot->x < filler->x_h)
	{
		dot->y = 0;
		while (dot->y < filler->y_w)
		{
			if (filler->map[dot->x][dot->y] == filler->player ||
			filler->map[dot->x][dot->y] == (filler->player + 32))
				distanse(filler, dot->x, dot->y);
			dot->y++;
		}
		dot->x++;
	}
}

void	hit_map(t_filler *filler)
{
	t_cord	dot;

	dot = (t_cord){0, 0};
	filler->first_hit = 1;
	filler->hit_map = (int**)malloc(sizeof(int*) * filler->x_h);
	while (dot.x < filler->x_h)
		filler->hit_map[dot.x++] = (int*)malloc(sizeof(int*) * filler->y_w);
	dot.x = 0;
	while (dot.x < filler->x_h)
	{
		dot.y = 0;
		while (dot.y < filler->y_w)
			filler->hit_map[dot.x][dot.y++] = -1;
		dot.x++;
	}
	dot.x = 0;
	loop_for_distance(filler, &dot);
}

int		can_set_token(t_filler *filler, int x, int y)
{
	int			only_one;
	t_cord		d;

	only_one = 0;
	d = (t_cord){0, 0};
	while (d.x < filler->token_h)
	{
		d.y = 0;
		while (d.y < filler->token_w)
		{
			if (only_one > 1 || x + d.x > (filler->x_h - 1) || y + d.y >
			(filler->y_w - 1) || ((filler->map[x + d.x][y + d.y] ==
			filler->enemy || filler->map[x + d.x][y + d.y] == filler->enemy +
			32) && filler->token[d.x][d.y] == '*'))
				return (0);
			if (filler->token[d.x][d.y] == '*' &&
			(filler->map[x + d.x][y + d.y] == filler->player ||
			filler->map[x + d.x][y + d.y] == filler->player + 32))
				only_one++;
			d.y++;
		}
		d.x++;
	}
	return (only_one);
}

void	set_min_sum(t_filler *filler, t_cord *dot, int *sum)
{
	while (dot->x < filler->x_h)
	{
		dot->y = 0;
		while (dot->y < filler->y_w)
		{
			*sum += filler->hit_map[dot->x][dot->y] > -1 ?
				filler->hit_map[dot->x][dot->y] : 0;
			dot->y++;
		}
		dot->x++;
	}
}
