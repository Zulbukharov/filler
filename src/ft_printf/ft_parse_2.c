/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:59:44 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/08 14:03:42 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_w_len(t_flags *flags)
{
	flags->w_len = flags->p_len > flags->w_len ?
		flags->p_len : flags->w_len;
	flags->f_zero = flags->p_len == flags->w_len
		? 1 : flags->f_zero;
	flags->f_minus = flags->f_zero && flags->w_len
		== flags->p_len ? 0 : flags->f_minus;
}

int		no_flags(char *format, t_flags *flags)
{
	if (check_for_mod(flags, format) == 1 ||
		check_for_width(format, flags) == 1 ||
		*format == '.' ||
		check_for_mod(flags, format) == 1 ||
		check_for_type(flags, *format) == 1 ||
		check_for_flag(flags, *format) == 1)
	{
		return (1);
	}
	return (0);
}

char	*set_flags(t_flags *flags, char *format)
{
	while (!format || *format != '\0')
	{
		if (check_for_flag(flags, *format) == 1)
			format++;
		else if ((*format >= 9 && *format <= 13) ||
			no_flags(format, flags) == 0)
			return (format);
		else if (check_for_width(format, flags) > 0)
			format += flags->w_step_len;
		else if (*format == '.' && check_for_prec(flags, ++format) > 0)
			format += ft_get_int_len((uintmax_t)flags->p_len);
		else if (check_for_mod(flags, format))
			format += flags->m_step_len;
		else if (check_for_type(flags, *format) > 0)
			return (++format);
		else
			format++;
	}
	return (format);
}
