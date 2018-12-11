/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:57:51 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/08 16:26:01 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_arr_float(t_main *main, t_flags *flags, t_float *floa)
{
	floa->f = main->llf - (int)main->llf;
	floa->d = (int)main->llf;
	floa->arr[floa->i] = floa->d;
	floa->i++;
	while (floa->f > 0 && floa->i <= flags->p_len + 1)
	{
		floa->f *= 10;
		floa->arr[floa->i] = (int)floa->f;
		floa->f -= (int)floa->f;
		floa->i++;
	}
	floa->i--;
	if (floa->i >= 0 && floa->arr[floa->i] >= 5 && floa->i - 1 >= 0)
		floa->arr[floa->i - 1]++;
	floa->i--;
}

void	print_float_2(t_flags *flags, t_float *floa)
{
	if (flags->f_space)
		ft_putchar(' ');
	if (flags->f_plus && flags->f_zero)
		ft_putchar(flags->min_plus);
	if (!flags->f_minus)
		print_whitespaces(flags, 0);
	if (flags->f_plus && !flags->f_zero)
		ft_putchar(flags->min_plus);
	if (flags->p_zero)
		print_int(floa->arr[0]);
	if (flags->f_hash && flags->p_zero)
		ft_putchar('.');
	else if (!flags->p_zero)
	{
		print_int(floa->arr[0]);
		ft_putchar('.');
		floa->w = 1;
		while (floa->w < flags->p_len)
		{
			print_int(floa->arr[floa->w]);
			floa->w++;
		}
	}
	if (flags->f_minus)
		print_whitespaces(flags, 0);
}

void	set_len(t_flags *flags, t_float *floa)
{
	int i;
	int z;
	int q;
	int w;

	i = 0;
	z = 0;
	q = 0;
	w = 0;
	i = flags->min_plus == minus && !flags->f_plus ? 1 : 0;
	z = flags->p_zero ? 0 : 1;
	q = flags->f_hash && flags->p_zero ? 1 : 0;
	w = flags->f_space ? 1 : 0;
	flags->w_len = flags->w_len > 0 && flags->p_len
		< flags->w_len ? flags->w_len -
		flags->f_plus - ft_get_int_len(floa->arr[0]) - i
		- flags->p_len - z - q - w : 0;
}

void	print_float(t_main *main, t_flags *flags)
{
	t_float floa;

	floa.i = 0;
	ft_bzero(floa.arr, 500);
	if (flags->f_plus && main->llf >= 0)
		flags->min_plus = plus;
	if (main->llf < 0)
	{
		flags->min_plus = minus;
		main->llf *= -1;
	}
	fill_arr_float(main, flags, &floa);
	while (floa.i >= 0)
	{
		if (floa.arr[floa.i] == 10 && floa.i - 1 >= 0)
		{
			floa.arr[floa.i - 1]++;
			floa.arr[floa.i] = 0;
		}
		else
			break ;
		floa.i--;
	}
	set_len(flags, &floa);
	print_float_2(flags, &floa);
}

void	get_float(t_main *main, t_flags *flags)
{
	main->f = !flags->m_l_float && !flags->m_l_int ?
		va_arg(main->arg, double) : main->f;
	main->lf = flags->m_l_int ? va_arg(main->arg, double) : main->lf;
	main->llf = flags->m_l_float ? va_arg(main->arg, long double) : main->llf;
	main->llf = !flags->m_l_float && !flags->m_l_int ? main->f : main->llf;
	main->llf = flags->m_l_int ? main->lf : main->llf;
	print_float(main, flags);
}
