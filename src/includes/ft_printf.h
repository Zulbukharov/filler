/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:43:09 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/09 15:30:52 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int						g_counter;

typedef enum			e_min_plus
{
	plus = 43,
	minus = 45
}						t_min_plus;

typedef enum			e_type
{
	no = 0,
	d,
	i,
	c,
	s,
	p,
	f,
	o,
	u,
	x,
	X,
	P,
}						t_type;

typedef struct			s_flags
{
	int					s_step1;
	int					f_minus;
	int					f_plus;
	int					f_hash;
	int					f_zero;
	int					f_space;
	int					f_hash_len;
	int					s_step2;
	int					w_arg_len;
	int					w_len;
	int					w_step_len;
	int					s_step3;
	int					p_len;
	int					p_zero;
	int					s_step4;
	int					m_h;
	int					m_hh;
	int					m_l_int;
	int					m_ll;
	int					m_l_float;
	int					m_step_len;
	int					s_step5;
	int					step;
	t_type				mod;
	int					int_len;
	t_min_plus			min_plus;
	int					int_step;
	int					k;
	int					di_len;
	int					f;
}						t_flags;

typedef struct			s_main
{
	va_list				arg;
	int					len;
	char				*string;
	char				sym;
	void				*p;
	long long			di;
	unsigned long long	lloux;
	float				f;
	double				lf;
	long double			llf;
	char				hex[1024];
	char				octal[1024];
	char				*tmp;
}						t_main;

typedef struct			s_hex
{
	int					i;
	int					d;
	char				hex[17];
	uintptr_t			p;
}						t_hex;

typedef struct			s_float
{
	long double			f;
	int					d;
	long long			arr[500];
	int					i;
	int					w;
}						t_float;

int						ft_printf(char *format, ...);
int						ft_get_int_len(long long value);
void					print_int(long long int nb);
void					print_uns(unsigned long long int nb);
int						ft_get_uns_len(unsigned long long value);
void					ft_upper_case(char *s);
void					zero_before_ples1(int len, t_flags *flags);
void					zero_before_ples(char *str, t_flags *flags);
int						check_for_flag(t_flags *flags, char c);
int						check_for_width(char *format, t_flags *flags);
int						check_for_prec(t_flags *flags, char *format);
int						check_for_type(t_flags *flags, char ch);
int						check_for_mod(t_flags *flags, char *format);
int						no_flags(char *format, t_flags *flags);
char					*set_flags(t_flags *flags, char *format);
void					print_whitespaces_2(t_flags *flags, int z);
void					print_whitespaces(t_flags *flags, int len);
void					print_float(t_main *main, t_flags *flags);
void					fill_arr_float(t_main *main, t_flags *flags,
										t_float *floa);
void					print_float_2(t_flags *flags, t_float *floa);
void					set_len(t_flags *flags, t_float *floa);
void					get_float(t_main *main, t_flags *flags);
char					hex_digit(int v);
void					print_add_hex(t_flags *flags, t_hex *hex);
void					print_add_hex_2(t_flags *flags, t_hex *hex);
void					print_address_hex(t_main *main, t_flags *flags);
void					get_address(t_main *main, t_flags *flags);
void					print_int_2(t_main *main, t_flags *flags);
void					print_int_3(t_main *main, t_flags *flags);
void					print_int_w(t_main *main, t_flags *flags);
void					get_int(t_main *main, t_flags *flags);
void					get_char(t_main *main, t_flags *flags);
void					print_string(t_main *main, t_flags *flags, char *q);
void					get_string(t_main *main, t_flags *flags);
void					print_hex_3(t_main *main, t_flags *flags);
void					print_hex2(t_main *main, t_flags *flags);
void					print_hex(t_main *main, t_flags *flags);
void					print_octal2(t_main *main, t_flags *flags);
void					print_octal(t_main *main, t_flags *flags);
void					print_percent(t_flags *flags);
void					print_unsigned(t_main *main, t_flags *flags);
void					get_hex_octal_unsigned(t_main *main, t_flags *flags);
void					set_w_len(t_flags *flags);
void					get_arg(t_main *main, t_flags *flags);
char					*check_for_pre(t_main *main, char *format);

#endif
