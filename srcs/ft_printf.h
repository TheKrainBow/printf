/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:50:13 by magostin          #+#    #+#             */
/*   Updated: 2020/08/25 14:29:04 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_float
{
	long int	temp_int;
	long double	temp;
	int			round;
	int			zero;
	int			i;
	int			j;
	int			ret;
	int			neg;
}				t_float;

typedef struct	s_arg
{
	char		flags;
	int			zero;
	char		type;
	int			width_exist;
	long int	width;
	int			accu;
	long int	accu_value;
	char		conv;
}				t_arg;

typedef struct	s_pf
{
	va_list		*ap;
	char		*str_pars;
	char		*str;
	t_arg		*arg;
	t_float		*s_float;
	int			n_c;
	int			error;
}				t_pf;

void			init_struct(t_pf *printf_s, char *str);
int				ft_printf(const char *str, ...);
void			ft_putchar(char c, t_pf *printf_s);
void			ft_find_type(t_pf *printf_s);
char			*ft_strchr_printf(const char *s, int c);
void			ft_parsing(t_pf *printf_s);

void			node_to_functions(t_pf *printf_s);
void			hh_node_to_functions(t_pf *printf_s);
void			h_node_to_functions(t_pf *printf_s);
void			ll_node_to_functions(t_pf *printf_s);
void			l_node_to_functions(t_pf *printf_s);

void			ft_putnbrbase(long long n, char *s, t_pf *pf_s);
void			ft_hx_recu(unsigned long long n, char *s, int s_b, t_pf *pf_s);
void			ft_puthexa(unsigned long long n, char *s, int s_b, t_pf *pf_s);
int				ft_sizenbr(long long number, int base_size);

void			ft_char_function(long long int n, t_pf *printf_s);
void			ft_string_function(char *s, t_pf *printf_s);
void			ft_number_function(long long int n, t_pf *printf_s);
void			ft_hexa_function(long int n, t_pf *printf_s);
void			ft_address_function(void *ptr, t_pf *printf_s);
void			ft_unsigned_function(unsigned long long n, t_pf *printf_s);

void			ft_float_function(long double n, t_pf *printf_s);
void			ft_float_print(long double n, t_pf *printf_s);
void			ft_print_whole(long double f, t_pf *printf_s);
void			init_float_struct(t_float *s_f, long double n, t_pf *printf_s);
int				ft_float_test(t_pf *printf_s);
void			ft_float_blanks(long int letter, t_pf *printf_s);

void			ft_sc_function(long double n, t_pf *printf_s);
void			ft_n_function(long long int *n, t_pf *printf_s);

void			ft_g_print(long double n, t_pf *printf_s);
void			ft_g_function(long double n, t_pf *printf_s);
void			get_zero(long double n, t_float *s_f, t_pf *printf_s);
int				get_exp(long double temp);

long double		clear_entier(long double f);
#endif
