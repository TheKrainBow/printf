/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:22:27 by magostin          #+#    #+#             */
/*   Updated: 2020/08/25 14:07:35 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				node_to_functions(t_pf *printf_s)
{
	if (printf_s->arg->type == 'c')
		ft_char_function(va_arg(*printf_s->ap, int), printf_s);
	else if (printf_s->arg->type == 's')
		ft_string_function(va_arg(*printf_s->ap, char *), printf_s);
	else if (ft_strchr("di", printf_s->arg->type))
		ft_number_function(va_arg(*printf_s->ap, int), printf_s);
	else if (ft_strchr("xX", printf_s->arg->type))
		ft_hexa_function(va_arg(*printf_s->ap, unsigned int), printf_s);
	else if (printf_s->arg->type == 'p')
		ft_address_function(va_arg(*printf_s->ap, void *), printf_s);
	else if (printf_s->arg->type == 'u')
		ft_unsigned_function(va_arg(*printf_s->ap, unsigned int), printf_s);
	else if (printf_s->arg->type == '%')
		ft_char_function('%', printf_s);
	else if (printf_s->arg->type == 'f')
		ft_float_function((long double)va_arg(*printf_s->ap, double), printf_s);
	else if (printf_s->arg->type == 'e')
		ft_sc_function((long double)va_arg(*printf_s->ap, double), printf_s);
	else if (printf_s->arg->type == 'g')
		ft_g_function((long double)va_arg(*printf_s->ap, double), printf_s);
	else if (printf_s->arg->type == 'n')
		ft_n_function(va_arg(*printf_s->ap, long long int *), printf_s);
}

void				l_node_to_functions(t_pf *printf_s)
{
	if (printf_s->arg->type == 'c')
		ft_char_function(va_arg(*printf_s->ap, long int), printf_s);
	else if (printf_s->arg->type == 's')
		ft_string_function(va_arg(*printf_s->ap, char *), printf_s);
	else if (ft_strchr("di", printf_s->arg->type))
		ft_number_function(va_arg(*printf_s->ap, long int), printf_s);
	else if (ft_strchr("xX", printf_s->arg->type))
		ft_hexa_function(va_arg(*printf_s->ap, unsigned long), printf_s);
	else if (printf_s->arg->type == 'p')
		ft_address_function(va_arg(*printf_s->ap, void *), printf_s);
	else if (printf_s->arg->type == 'u')
		ft_unsigned_function(va_arg(*printf_s->ap, unsigned long), printf_s);
	else if (printf_s->arg->type == '%')
		ft_char_function('%', printf_s);
	else if (printf_s->arg->type == 'f')
		ft_float_function(va_arg(*printf_s->ap, double), printf_s);
	else if (printf_s->arg->type == 'n')
		ft_n_function(va_arg(*printf_s->ap, long long int *), printf_s);
}

void				ll_node_to_functions(t_pf *printf_s)
{
	if (printf_s->arg->type == 'c')
		ft_char_function(va_arg(*printf_s->ap, long long int), printf_s);
	else if (printf_s->arg->type == 's')
		ft_string_function(va_arg(*printf_s->ap, char *), printf_s);
	else if (ft_strchr("di", printf_s->arg->type))
		ft_number_function(va_arg(*printf_s->ap, long long int), printf_s);
	else if (ft_strchr("xX", printf_s->arg->type))
		ft_hexa_function(va_arg(*printf_s->ap,
		unsigned long long int), printf_s);
	else if (printf_s->arg->type == 'p')
		ft_address_function(va_arg(*printf_s->ap, void *), printf_s);
	else if (printf_s->arg->type == 'u')
		ft_unsigned_function(va_arg(*printf_s->ap,
		unsigned long long int), printf_s);
	else if (printf_s->arg->type == '%')
		ft_char_function('%', printf_s);
	else if (printf_s->arg->type == 'f')
		ft_float_function(va_arg(*printf_s->ap, double), printf_s);
	else if (printf_s->arg->type == 'n')
		ft_n_function(va_arg(*printf_s->ap, long long int *), printf_s);
}

void				h_node_to_functions(t_pf *printf_s)
{
	if (printf_s->arg->type == 'c')
		ft_char_function(va_arg(*printf_s->ap, int), printf_s);
	else if (printf_s->arg->type == 's')
		ft_string_function(va_arg(*printf_s->ap, char *), printf_s);
	else if (ft_strchr("di", printf_s->arg->type))
		ft_number_function((short)va_arg(*printf_s->ap, int), printf_s);
	else if (ft_strchr("xX", printf_s->arg->type))
		ft_hexa_function((unsigned short)va_arg(*printf_s->ap,
		unsigned int), printf_s);
	else if (printf_s->arg->type == 'p')
		ft_address_function(va_arg(*printf_s->ap, void *), printf_s);
	else if (printf_s->arg->type == 'u')
		ft_unsigned_function((unsigned short)va_arg(*printf_s->ap,
		unsigned int), printf_s);
	else if (printf_s->arg->type == '%')
		ft_char_function('%', printf_s);
	else if (printf_s->arg->type == 'f')
		ft_float_function(va_arg(*printf_s->ap, double), printf_s);
	else if (printf_s->arg->type == 'n')
		ft_n_function(va_arg(*printf_s->ap, long long int *), printf_s);
}

void				hh_node_to_functions(t_pf *printf_s)
{
	if (printf_s->arg->type == 'c')
		ft_char_function(va_arg(*printf_s->ap, int), printf_s);
	else if (printf_s->arg->type == 's')
		ft_string_function(va_arg(*printf_s->ap, char *), printf_s);
	else if (ft_strchr("di", printf_s->arg->type))
		ft_number_function((char)va_arg(*printf_s->ap, int), printf_s);
	else if (ft_strchr("xX", printf_s->arg->type))
		ft_hexa_function((unsigned char)va_arg(*printf_s->ap,
		unsigned int), printf_s);
	else if (printf_s->arg->type == 'p')
		ft_address_function(va_arg(*printf_s->ap, void *), printf_s);
	else if (printf_s->arg->type == 'u')
		ft_unsigned_function((unsigned char)va_arg(*printf_s->ap,
		unsigned int), printf_s);
	else if (printf_s->arg->type == '%')
		ft_char_function('%', printf_s);
	else if (printf_s->arg->type == 'f')
		ft_float_function(va_arg(*printf_s->ap, double), printf_s);
	else if (printf_s->arg->type == 'n')
		ft_n_function(va_arg(*printf_s->ap, long long int *), printf_s);
}
