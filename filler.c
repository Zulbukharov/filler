/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:35:54 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/12 19:31:46 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
