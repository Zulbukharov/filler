/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:19:01 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/06 17:52:39 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *str, int ch)
{
	char *s;

	s = (char*)str;
	while (*s)
	{
		if (*s == ch)
			return (s);
		s++;
	}
	if (ch == 0)
		return (s);
	return (NULL);
}
