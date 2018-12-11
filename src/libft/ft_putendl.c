/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 20:38:52 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/06 17:52:10 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putendl(char const *s)
{
	size_t	l;

	if (!s)
		return ;
	l = ft_strlen(s);
	write(1, s, l);
	ft_putchar('\n');
}
