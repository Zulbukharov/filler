/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:57:39 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/08 14:02:44 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int_2(t_main *main, t_flags *flags)
{
	if (flags->f_minus && flags->p_len >
		flags->di_len && flags->w_len > flags->p_len)
	{
		if (flags->f_plus && !flags->int_step && main->di >= 0)
		{
			ft_putchar(flags->min_plus);
			flags->int_step++;
		}
		if (flags->f_minus)
			zero_before_ples1(flags->di_len, flags);
	}
	if (flags->f_zero && flags->f_plus && !flags->int_step && main->di >= 0)
	{
		ft_putchar(flags->min_plus);
		flags->int_step++;
	}
	if (flags->w_len > 0 && !flags->f_minus)
	{
		print_whitespaces(flags, flags->di_len);
		if (flags->f_plus && !flags->int_step && main->di >= 0)
		{
			ft_putchar(flags->min_plus);
			flags->int_step++;
		}
	}
}

void	print_int_3(t_main *main, t_flags *flags)
{
	if (!flags->f_minus)
	{
		zero_before_ples1(flags->di_len, flags);
	}
	if (!flags->f_zero && flags->f_plus && !flags->int_step && main->di >= 0)
		ft_putchar(flags->min_plus);
	if (flags->di_len > 0)
		print_int(main->di);
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, flags->di_len);
}

void	print_int_w(t_main *main, t_flags *flags)
{
	flags->di_len = ft_get_int_len(main->di);
	if (main->di == 0 && flags->p_zero)
		flags->di_len = 0;
	if (flags->f_plus && main->di >= 0)
	{
		flags->int_len++;
		flags->min_plus = plus;
	}
	if (main->di < 0)
	{
		flags->min_plus = minus;
		flags->f_plus = 1;
		main->di *= -1;
		flags->int_len++;
	}
	flags->int_len = flags->p_len == flags->w_len ? 0 : flags->int_len;
	if (flags->f_space > 0 && flags->min_plus == 0)
	{
		ft_putchar(' ');
		flags->int_len++;
	}
	flags->k = flags->w_len > flags->p_len &&
		flags->p_len > flags->di_len ? 1 : flags->k;
	print_int_2(main, flags);
	print_int_3(main, flags);
}

void	get_int(t_main *main, t_flags *flags)
{
	main->di = va_arg(main->arg, long long);
	main->di = !flags->m_h && !flags->m_l_int ? (int)main->di : main->di;
	main->di = flags->m_hh ? (signed char)main->di : main->di;
	main->di = flags->m_h && !flags->m_hh ? (short)main->di : main->di;
	main->di = flags->m_l_int && !flags->m_ll ? (long)main->di : main->di;
	main->di = flags->m_l_int && flags->m_ll ? (long long)main->di : main->di;
	print_int_w(main, flags);
}
