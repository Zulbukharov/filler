/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_white_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:00:53 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/08 14:01:17 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		zero_before_ples1(int len, t_flags *flags)
{
	int b;

	b = 0;
	if (flags->p_len > len && flags->w_len > flags->p_len)
	{
		b = flags->p_len - len;
		while (b > 0)
		{
			ft_putchar('0');
			b--;
		}
	}
}

void		zero_before_ples(char *str, t_flags *flags)
{
	int b;

	b = 0;
	if (flags->p_len > (int)ft_strlen(str) && flags->w_len > flags->p_len)
	{
		b = flags->p_len - ft_strlen(str);
		while (b > 0)
		{
			ft_putchar('0');
			b--;
		}
	}
}

void		print_whitespaces_2(t_flags *flags, int z)
{
	if (flags->mod == d || flags->mod == i || flags->mod == u)
	{
		while (z > 0)
		{
			if (flags->f_zero && !flags->k)
				ft_putchar('0');
			else
				ft_putchar(' ');
			z--;
		}
	}
	else
	{
		while (z > 0)
		{
			if (flags->f_zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			z--;
		}
	}
}

void		print_whitespaces(t_flags *flags, int len)
{
	int z;

	if (flags->mod == x || flags->mod == X ||
	flags->mod == o || flags->mod == p)
	{
		z = flags->w_len - len - flags->f_hash_len;
		if (flags->p_len < flags->w_len && flags->p_len > len)
			z = z - (flags->p_len - len);
	}
	else if (flags->mod == i || flags->mod == d || flags->mod == u)
	{
		z = flags->w_len - len - flags->int_len;
		if (flags->p_len < flags->w_len && flags->p_len > len)
			z = z - (flags->p_len - len);
	}
	else
		z = flags->w_len - len;
	print_whitespaces_2(flags, z);
}
