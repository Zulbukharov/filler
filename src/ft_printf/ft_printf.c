/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:42:04 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/08 14:04:10 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_char(t_main *main, t_flags *flags)
{
	main->sym = 0;
	main->sym = va_arg(main->arg, int);
	if (flags->w_len > 0 && !flags->f_minus)
		print_whitespaces(flags, 1);
	ft_putchar(main->sym);
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, 1);
}

void	print_string(t_main *main, t_flags *flags, char *q)
{
	flags->f = 0;
	if (main->string == NULL)
		main->string = q;
	if (flags->p_len > 0 || flags->p_zero)
	{
		if (flags->p_zero && !flags->f)
			main->string = "";
		else if (flags->p_len < (int)ft_strlen(main->string))
		{
			main->string = ft_strsub(main->string, 0, flags->p_len);
			flags->f = 2;
		}
	}
	if (flags->w_len > 0 && !flags->f_minus)
		print_whitespaces(flags, ft_strlen(main->string));
	ft_putstr(main->string);
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, ft_strlen(main->string));
	if (flags->f == 2)
	{
		free(main->string);
		main->string = NULL;
	}
}

void	get_arg(t_main *main, t_flags *flags)
{
	flags->f_zero = flags->f_minus ? 0 : flags->f_zero;
	flags->f_space = flags->f_hash ? 0 : flags->f_space;
	if (flags->mod == d || flags->mod == x || flags->mod == X ||
		flags->mod == o || flags->mod == i || flags->mod == u ||
		flags->mod == p)
		set_w_len(flags);
	if (flags->mod == f)
	{
		flags->p_len = flags->p_len > 0 ? flags->p_len : 6;
		flags->p_len = flags->p_zero ? 0 : flags->p_len;
		get_float(main, flags);
	}
	else if (flags->mod == p)
		get_address(main, flags);
	else if (flags->mod == d || flags->mod == i)
		get_int(main, flags);
	else if (flags->mod == x || flags->mod == X || flags->mod == o ||
		flags->mod == u)
		get_hex_octal_unsigned(main, flags);
	else if (flags->mod == c)
		get_char(main, flags);
	else if (flags->mod == s)
		get_string(main, flags);
	else if (flags->mod == P)
		print_percent(flags);
}

char	*check_for_pre(t_main *main, char *format)
{
	t_flags flags;

	format++;
	flags = (t_flags){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	format = set_flags(&flags, format);
	get_arg(main, &flags);
	return (format);
}

int		ft_printf(char *format, ...)
{
	t_main main;

	va_start(main.arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
			format = check_for_pre(&main, format);
		else
			ft_putchar(*format++);
	}
	va_end(main.arg);
	return (g_counter);
}
