/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:41:53 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/12 19:35:33 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <ft_printf.h>
# define ABS(X)(((X)<0)?-(X):(X))

typedef enum		e_player
{
	p1 = 79,
	p2 = 88
}					t_player;

typedef	struct		s_util
{
	int				i;
	int				x;
	char			*old;
}					t_util;

typedef struct		s_min
{
	int				x;
	int				y;
	int				sum;
	int				min;
}					t_min;

typedef struct		s_cord
{
	int				x;
	int				y;
}					t_cord;

typedef struct		s_filler
{
	int				first_read;
	int				x_h;
	int				y_w;
	int				token_h;
	int				token_w;
	char			*line;
	char			**map;
	char			**token;

	int				first_hit;
	int				sum_of_hit;
	t_player		player;
	t_player		enemy;
	int				**hit_map;
	int				done;
}					t_filler;

void				loop_token(t_filler *filler, t_util *u);
void				read_token(t_filler *filler);
void				read_loop(t_filler *filler, t_util *u);
void				read_map(t_filler *filler);
int					read_first_line(t_filler *filler);
void				distanse(t_filler *filler, int x, int y);
void				loop_for_distance(t_filler *filler, t_cord *dot);
void				hit_map(t_filler *filler);
int					can_set_token(t_filler *filler, int x, int y);
void				set_min_sum(t_filler *filler, t_cord *dot, int *sum);
int					sum_of_hit(t_filler *filler, int x, int y);
void				destroy_filler(t_filler *filler);
void				return_value(t_filler *filler, t_min min);
void				set_token(t_filler *filler);

#endif
