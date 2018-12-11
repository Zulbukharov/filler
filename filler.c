/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:35:54 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/11 23:58:09 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_token(t_filler *filler)
{
	t_util u;

	u = (t_util){0, 0, 0};
	filler->line = NULL;
	ft_get_next_line(0, &filler->line);
	while (!ft_isnum(filler->line[u.i]))
		u.i++;
	filler->token_h = ft_atoi(&filler->line[u.i]);
	filler->token_w = ft_atoi(&filler->line[u.i +
	ft_get_int_len(filler->token_h)]);
	filler->token = (char**)malloc(sizeof(char*) * filler->token_h);
	u.i = 0;
	while (u.i < filler->token_h)
		filler->token[u.i++] = (char*)malloc(sizeof(char) * filler->token_w);
	free(filler->line);
	u.x = 0;
	while (u.x < filler->token_h)
	{
		u.i = 0;
		ft_get_next_line(0, &filler->line);
		while (filler->line[u.i] && u.i < filler->token_w)
		{
			filler->token[u.x][u.i] = filler->line[u.i];
			u.i++;
		}
		u.x++;
		free(filler->line);
	}
}

void	read_loop(t_filler *filler, t_util *u)
{
	while (u->x < filler->x_h)
	{
		u->i = 0;
		ft_get_next_line(0, &filler->line);
		u->old = filler->line;
		while (ft_isnum(*filler->line) == 1 || *filler->line == ' ')
			filler->line++;
		while (u->i < filler->y_w)
		{
			filler->map[u->x][u->i] = filler->line[u->i];
			u->i++;
		}
		u->x++;
		free(u->old);
		filler->line = NULL;
		u->old = NULL;
	}
}

void	read_map(t_filler *filler)
{
	t_util u;

	u = (t_util){0, 0, 0};
	filler->line = NULL;
	ft_get_next_line(0, &filler->line);
	while (ft_isnum(filler->line[u.i]) == 0)
		u.i++;
	filler->x_h = ft_atoi(&filler->line[u.i]);
	filler->y_w = ft_atoi(&filler->line[u.i + ft_get_int_len(filler->x_h)]);
	filler->map = (char**)malloc(sizeof(char*) * filler->x_h);
	u.x = 0;
	while (u.x < filler->x_h)
	{
		filler->map[u.x] = (char*)malloc(sizeof(char) * filler->y_w);
		u.x++;
	}
	free(filler->line);
	filler->line = NULL;
	u.x = 0;
	ft_get_next_line(0, &filler->line);
	free(filler->line);
	filler->line = NULL;
	read_loop(filler, &u);
}

int		read_first_line(t_filler *filler)
{
	int z;

	filler->line = NULL;
	ft_get_next_line(0, &filler->line);
	z = (ft_atoi(ft_strchr(filler->line, 'p') + 1));
	if (z == 1)
	{
		filler->enemy = p2;
		filler->player = p1;
	}
	else if (z == 2)
	{
		filler->player = p2;
		filler->enemy = p1;
	}
	free(filler->line);
	return (1);
}

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
				s = (abs(dot.x - x)) + (abs(dot.y - y));
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

int		sum_of_hit(t_filler *filler, int x, int y)
{
	int		sum;
	t_cord	dot;

	sum = 0;
	dot = (t_cord){0, 0};
	while (dot.x < filler->token_h)
	{
		dot.y = 0;
		while (dot.y < filler->token_w)
		{
			if (filler->token[dot.x][dot.y] == '*')
				distanse(filler, x + dot.x, y + dot.y);
			dot.y++;
		}
		dot.x++;
	}
	dot.x = 0;
	set_min_sum(filler, &dot, &sum);
	return (sum);
}

void	destroy_filler(t_filler *filler)
{
	t_cord dot;

	dot = (t_cord){0, 0};
	while (dot.x < filler->x_h)
	{
		free(filler->map[dot.x]);
		free(filler->hit_map[dot.x]);
		filler->map[dot.x] = NULL;
		filler->hit_map[dot.x] = NULL;
		dot.x++;
	}
	dot.x = 0;
	free(filler->map);
	free(filler->hit_map);
	filler->map = NULL;
	filler->hit_map = NULL;
	while (dot.x < filler->token_h)
	{
		free(filler->token[dot.x]);
		filler->token[dot.x] = NULL;
		dot.x++;
	}
	free(filler->token);
	filler->token = NULL;
}

void	return_value(t_filler *filler, t_min min)
{
	destroy_filler(filler);
	if (min.min != -1)
		ft_printf("%d %d\n", min.x, min.y);
	else
	{
		ft_printf("%d %d\n", 0, 0);
		filler->done = 1;
	}
}

void	set_token(t_filler *filler)
{
	t_cord	dot;
	t_min	min;

	min = (t_min){0, 0, 0, -1};
	dot = (t_cord){0, 0};
	while (dot.x < filler->x_h)
	{
		dot.y = 0;
		while (dot.y < filler->y_w)
		{
			if (can_set_token(filler, dot.x, dot.y) == 1)
			{
				min.sum = sum_of_hit(filler, dot.x, dot.y);
				if (min.sum < min.min || min.min == -1)
				{
					min.min = min.sum;
					min.x = dot.x;
					min.y = dot.y;
				}
			}
			dot.y++;
		}
		dot.x++;
	}
	return_value(filler, min);
}

int		main(void)
{
	int			i;
	t_filler	filler;

	i = 0;
	filler = (t_filler){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (!filler.done)
	{
		i = i == 0 ? read_first_line(&filler) : 1;
		read_map(&filler);
		read_token(&filler);
		hit_map(&filler);
		set_token(&filler);
	}
	return (0);
}
