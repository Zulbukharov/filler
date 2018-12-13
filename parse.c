/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:31:23 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/12 19:31:31 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	loop_token(t_filler *filler, t_util *u)
{
	while (u->x < filler->token_h)
	{
		u->i = 0;
		ft_get_next_line(0, &filler->line);
		while (filler->line[u->i] && u->i < filler->token_w)
		{
			filler->token[u->x][u->i] = filler->line[u->i];
			u->i++;
		}
		u->x++;
		free(filler->line);
	}
}

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
	loop_token(filler, &u);
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
