/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:41:53 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/10 16:27:11 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <ft_printf.h>
# define abs(x)(((x)<0)?-(x):(x))

typedef enum		e_player
{
	p1 = 79, //O
	p2 = 88 // X
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

#endif
