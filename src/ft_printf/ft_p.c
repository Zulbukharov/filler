/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:02:16 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/08 14:02:22 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

void	print_add_hex(t_flags *flags, t_hex *hex)
{
	if (flags->f_minus)
		zero_before_ples(&hex->hex[hex->d], flags);
	if (flags->p_zero > 0)
	{
		ft_putstr("0x");
		if (flags->w_len > 0 && !flags->f_minus)
			print_whitespaces(flags, 0);
	}
	else
	{
		if (flags->w_len > 0 && flags->f_zero && !flags->f_minus)
			ft_putstr("0x0");
		if (flags->w_len > 0 && !flags->f_minus && flags->w_len
			> flags->p_len)
			print_whitespaces(flags, 1);
		else if (!flags->f_minus && flags->w_len == flags->p_len)
			print_whitespaces(flags, -1);
		if (!flags->f_zero)
			ft_putstr("0x0");
		if (!flags->f_minus)
			zero_before_ples(&hex->hex[hex->d], flags);
	}
}

void	print_add_hex_2(t_flags *flags, t_hex *hex)
{
	if (flags->p_len == flags->w_len)
		flags->f_hash_len = 0;
	if (flags->f_minus)
		zero_before_ples(&hex->hex[hex->d], flags);
	if (flags->f_zero)
		ft_putstr("0x");
	if (flags->w_len > 0 && !flags->f_minus)
		print_whitespaces(flags, ft_strlen(&hex->hex[hex->d]));
	if (!flags->f_minus)
		zero_before_ples(&hex->hex[hex->d], flags);
	if (!flags->f_zero)
		ft_putstr("0x");
	ft_putstr(&hex->hex[hex->d]);
}

void	print_address_hex(t_main *main, t_flags *flags)
{
	t_hex hex;

	hex.p = (uintptr_t)main->p;
	hex.i = (sizeof(hex.p) << 3) - 4;
	hex.d = 0;
	while (hex.i >= 0)
	{
		hex.hex[hex.d] = hex_digit((hex.p >> hex.i) & 0xf);
		hex.i -= 4;
		hex.d++;
	}
	hex.d = 0;
	while (hex.d < 16 && hex.hex[hex.d] == '0')
		hex.d++;
	hex.hex[16] = '\0';
	flags->f_hash = 1;
	flags->f_hash_len = 2;
	if (!hex.hex[hex.d])
		print_add_hex(flags, &hex);
	else
		print_add_hex_2(flags, &hex);
	if (flags->w_len > 0 && flags->f_minus && hex.hex[hex.d])
		print_whitespaces(flags, ft_strlen(&hex.hex[hex.d]));
	if (flags->w_len > 0 && flags->f_minus && !hex.hex[hex.d])
		print_whitespaces(flags, 1);
}

void	get_address(t_main *main, t_flags *flags)
{
	main->p = NULL;
	main->p = va_arg(main->arg, void*);
	print_address_hex(main, flags);
}
