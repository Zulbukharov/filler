/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:01:45 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/08 14:03:35 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_3(t_main *main, t_flags *flags)
{
	if (flags->w_len > 0 && !flags->f_minus)
		print_whitespaces(flags, 0);
	if (!flags->f_minus)
		zero_before_ples(main->hex, flags);
	ft_putchar('0');
}

void	print_hex2(t_main *main, t_flags *flags)
{
	if (flags->f_hash && flags->p_len >= flags->w_len)
		flags->f_hash_len = 0;
	if (flags->f_minus)
		zero_before_ples(main->hex, flags);
	if (flags->f_zero && flags->f_hash && flags->mod == x)
		ft_putstr("0x");
	if (flags->f_zero && flags->f_hash && flags->mod == X)
		ft_putstr("0X");
	if (flags->w_len > 0 && !flags->f_minus)
		print_whitespaces(flags, ft_strlen(main->hex));
	if (!flags->f_minus)
		zero_before_ples(main->hex, flags);
	if (flags->mod == X)
		ft_upper_case(main->hex);
	if (!flags->f_zero && flags->f_hash && flags->mod == x)
		ft_putstr("0x");
	if (!flags->f_zero && flags->f_hash && flags->mod == X)
		ft_putstr("0X");
	ft_putstr(main->hex);
}

void	print_hex(t_main *main, t_flags *flags)
{
	main->tmp = NULL;
	ft_bzero(main->hex, 1024);
	main->tmp = ft_itoa_base_10_16(main->lloux);
	ft_strcpy(main->hex, main->tmp);
	if (main->tmp)
		free(main->tmp);
	if (!*main->hex && ft_strlen(main->hex) == 0)
	{
		flags->f_hash_len = 0;
		if (flags->f_minus)
			zero_before_ples(main->hex, flags);
		if (flags->p_zero > 0)
		{
			if (flags->w_len > 0 && !flags->f_minus)
				print_whitespaces(flags, 0);
		}
		else
			print_hex_3(main, flags);
	}
	else
		print_hex2(main, flags);
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, ft_strlen(main->hex));
}

void	get_hex_octal_unsigned(t_main *main, t_flags *flags)
{
	main->lloux = va_arg(main->arg, unsigned long long);
	main->lloux = !flags->m_h && !flags->m_l_int ?
		(unsigned int)main->lloux : main->lloux;
	main->lloux = flags->m_h && !flags->m_hh ?
		(unsigned short)main->lloux : main->lloux;
	main->lloux = flags->m_hh ? (unsigned char)main->lloux : main->lloux;
	main->lloux = flags->m_l_int && !flags->m_ll
		? (unsigned long)main->lloux : main->lloux;
	main->lloux = flags->m_ll ?
		(unsigned long long)main->lloux : main->lloux;
	if (flags->mod == x || flags->mod == X)
		print_hex(main, flags);
	else if (flags->mod == o)
	{
		flags->f_hash_len = flags->f_hash ? 1 : 0;
		print_octal(main, flags);
	}
	else if (flags->mod == u)
		print_unsigned(main, flags);
}
