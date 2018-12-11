/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:58:09 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/08 14:00:27 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_get_int_len(long long value)
{
	int l;

	l = !value;
	while (value)
	{
		l++;
		value /= 10;
	}
	return (l);
}

void		print_int(long long int nb)
{
	if (nb == INTMAX_MIN)
		ft_putstr("-9223372036854775808");
	if (nb < 0 && nb != INTMAX_MIN)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10 && nb != INTMAX_MIN)
	{
		print_int(nb / 10);
		print_int(nb % 10);
	}
	else if (nb != INTMAX_MIN)
	{
		ft_putchar(nb + '0');
	}
}

void		print_uns(unsigned long long int nb)
{
	if (nb == INTMAX_MAX)
		ft_putstr("9223372036854775807");
	if (nb >= 10 && nb != INTMAX_MAX)
	{
		print_uns(nb / 10);
		print_uns(nb % 10);
	}
	else if (nb != INTMAX_MAX)
	{
		ft_putchar(nb + '0');
	}
}

int			ft_get_uns_len(unsigned long long value)
{
	int l;

	l = 0;
	while (value)
	{
		l++;
		value /= 10;
	}
	return (l);
}

void		ft_upper_case(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
}
