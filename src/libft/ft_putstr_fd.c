/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 20:46:18 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/06 17:52:21 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_fd(char const *s, int fd)
{
	size_t	l;

	if (!s || !fd)
		return ;
	l = ft_strlen(s);
	write(fd, s, l);
}
