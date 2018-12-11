/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:57:20 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/08 13:59:10 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_for_flag(t_flags *flags, char c)
{
	if (c == '-' || c == '+' || c == '#' || c == '0' || c == ' ')
	{
		flags->f_minus = c == '-' ? 1 : flags->f_minus;
		flags->f_plus = c == '+' ? 1 : flags->f_plus;
		flags->f_hash = c == '#' ? 1 : flags->f_hash;
		flags->f_zero = c == '0' ? 1 : flags->f_zero;
		flags->f_space = c == ' ' ? 1 : flags->f_space;
		flags->f_hash_len = flags->f_hash ? 2 : flags->f_hash_len;
		return (1);
	}
	else
		return (0);
}

int		check_for_width(char *format, t_flags *flags)
{
	if (ft_atoi(&(*format)) > 0)
	{
		flags->w_len = ft_atoi(format);
		flags->w_step_len = ft_get_int_len((long long)flags->w_len);
		flags->s_step2 = 1;
		return (1);
	}
	return (0);
}

int		check_for_prec(t_flags *flags, char *format)
{
	if (!*format)
		return (0);
	flags->p_len = ft_atoi(format);
	if (!flags->p_len)
	{
		flags->p_zero = 1;
		return (0);
	}
	return (1);
}

int		check_for_type(t_flags *flags, char ch)
{
	if (ch == 'd' || ch == 'i' || ch == 'c' ||
	ch == 's' || ch == 'p' || ch == 'f' ||
	ch == 'o' || ch == 'u' || ch == 'x' ||
	ch == 'X' || ch == '%')
	{
		flags->mod = ch == 'd' ? d : flags->mod;
		flags->mod = ch == 'i' ? i : flags->mod;
		flags->mod = ch == 'c' ? c : flags->mod;
		flags->mod = ch == 's' ? s : flags->mod;
		flags->mod = ch == 'p' ? p : flags->mod;
		flags->mod = ch == 'f' ? f : flags->mod;
		flags->mod = ch == 'o' ? o : flags->mod;
		flags->mod = ch == 'u' ? u : flags->mod;
		flags->mod = ch == 'x' ? x : flags->mod;
		flags->mod = ch == 'X' ? X : flags->mod;
		flags->mod = ch == '%' ? P : flags->mod;
		return (1);
	}
	return (0);
}

int		check_for_mod(t_flags *flags, char *format)
{
	int d;

	d = 0;
	if ((d = ft_strncmp(format, "h", 1) == 0 ? 1 : d) > 0 ||
	(d = ft_strncmp(format, "l", 1) == 0 ? 1 : d) > 0 ||
	(d = ft_strncmp(format, "L", 1) == 0 ? 1 : d) > 0 ||
	(d = ft_strncmp(format, "hh", 2) == 0 ? 2 : d) > 0 ||
	(d = ft_strncmp(format, "ll", 2) == 0 ? 2 : d) > 0)
	{
		flags->m_hh = ft_strncmp(format, "hh", 2) == 0 ? 1 : flags->m_hh;
		flags->m_h = ft_strncmp(format, "h", 1) == 0 ? 1 : flags->m_h;
		flags->m_l_int = ft_strncmp(format, "l", 1) == 0 ? 1 : flags->m_l_int;
		flags->m_ll = ft_strncmp(format, "ll", 2) == 0 ? 1 : flags->m_ll;
		flags->m_l_float = ft_strncmp(format, "L", 1) == 0 ? 1
			: flags->m_l_float;
		flags->m_step_len = d;
		return (1);
	}
	return (0);
}
