/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_osc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:04:22 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/08 14:04:31 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_string(t_main *main, t_flags *flags)
{
	main->string = va_arg(main->arg, char*);
	print_string(main, flags, "(null)");
}

void	print_octal2(t_main *main, t_flags *flags)
{
	if (!flags->f_zero && flags->f_hash && flags->mod == o)
		ft_putstr("0");
	ft_putstr(main->octal);
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, ft_strlen(main->octal));
}

void	print_octal(t_main *main, t_flags *flags)
{
	main->tmp = NULL;
	ft_bzero(main->octal, 1024);
	main->tmp = ft_itoa_base_10_8(main->lloux);
	ft_strcpy(main->octal, main->tmp);
	if (main->tmp)
		free(main->tmp);
	if (ft_strlen(main->octal) == 0 && !flags->p_zero)
		ft_putchar('0');
	else
	{
		if (flags->f_minus && flags->p_len >
			(int)ft_strlen(main->octal) && flags->w_len > flags->p_len)
			if (flags->f_minus)
				zero_before_ples(main->octal, flags);
		if (flags->f_zero && flags->f_hash && flags->mod == o)
			ft_putstr("0");
		if (flags->w_len > 0 && !flags->f_minus)
			print_whitespaces(flags, ft_strlen(main->octal));
		if (!flags->f_minus)
			zero_before_ples(main->octal, flags);
		print_octal2(main, flags);
	}
}

void	print_percent(t_flags *flags)
{
	if (flags->w_len > 0 && !flags->f_minus)
		print_whitespaces(flags, 1);
	ft_putchar('%');
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, 1);
}

void	print_unsigned(t_main *main, t_flags *flags)
{
	flags->di_len = ft_get_uns_len(main->lloux);
	flags->int_len = flags->p_len == flags->w_len ? 0 : flags->int_len;
	flags->k = flags->w_len > flags->p_len && flags->p_len
		> flags->di_len ? 1 : flags->k;
	if (main->lloux == 0 && flags->p_zero)
		flags->di_len = 0;
	if (flags->f_minus && flags->p_len >
		flags->di_len && flags->w_len > flags->p_len)
	{
		if (flags->f_minus)
			zero_before_ples1(flags->di_len, flags);
	}
	if (flags->w_len > 0 && !flags->f_minus)
	{
		print_whitespaces(flags, flags->di_len);
	}
	if (!flags->f_minus)
	{
		zero_before_ples1(flags->di_len, flags);
	}
	if (!flags->p_zero)
		print_uns(main->lloux);
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, flags->di_len);
}
