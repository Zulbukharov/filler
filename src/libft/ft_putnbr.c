/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 20:43:01 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/06 17:52:17 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = -147483648;
		}
		nb = -nb;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}
