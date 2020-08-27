/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:40:22 by magostin          #+#    #+#             */
/*   Updated: 2020/08/25 13:44:48 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_find_conv(t_pf *printf_s)
{
	if (*printf_s->str == 'l' && *(printf_s->str + 1) == 'l')
		printf_s->arg->conv = 'L';
	else if (*printf_s->str == 'l' && *(printf_s->str + 1) != 'l')
		printf_s->arg->conv = 'l';
	else if (*printf_s->str == 'h' && *(printf_s->str + 1) == 'h')
		printf_s->arg->conv = 'H';
	else if (*printf_s->str == 'h' && *(printf_s->str + 1) != 'h')
		printf_s->arg->conv = 'h';
	while (*printf_s->str == 'l' || *printf_s->str == 'h')
		printf_s->str++;
}

void				ft_find_flags(t_pf *printf_s)
{
	if (*printf_s->str == '0' && *(printf_s->str + 1) != '-' &&
	((!ft_strchr_printf(printf_s->str, '.') &&
	ft_strchr("iuxXdfeg", printf_s->arg->type))
	|| !ft_strchr("iuxXdeg", printf_s->arg->type)))
		printf_s->arg->flags = '0';
	else if (*printf_s->str == '-' || *(printf_s->str + 1) == '-')
		printf_s->arg->flags = '-';
	else
		printf_s->arg->flags = 0;
	if (ft_strchr_printf("0", *printf_s->str))
		printf_s->arg->zero = 1;
	else
		printf_s->arg->zero = 0;
	while (ft_strchr_printf("0-", *printf_s->str))
		printf_s->str++;
}

void				ft_find_width(t_pf *printf_s)
{
	printf_s->arg->width_exist = 1;
	if (*printf_s->str == '*')
	{
		printf_s->arg->width = va_arg(*printf_s->ap, int);
		if (printf_s->arg->width < 0)
		{
			printf_s->arg->flags = '-';
			printf_s->arg->width *= -1;
		}
		printf_s->str++;
	}
	else if (ft_strchr_printf("123456789", *printf_s->str))
	{
		printf_s->arg->width = ft_atoi(printf_s->str);
		while (ft_strchr_printf("1234567890", *printf_s->str))
			printf_s->str++;
	}
}

void				ft_find_accu_value(t_pf *printf_s)
{
	printf_s->str++;
	printf_s->arg->accu = 1;
	if (*printf_s->str == '*')
	{
		printf_s->arg->accu_value = va_arg(*printf_s->ap, int);
		printf_s->str++;
	}
	else if (ft_strchr_printf("1234567890", *printf_s->str))
	{
		printf_s->arg->accu_value = ft_atoi(printf_s->str);
		while (ft_strchr_printf("1234567890", *printf_s->str))
			printf_s->str++;
	}
}

void				ft_parsing(t_pf *printf_s)
{
	init_struct(printf_s, printf_s->str);
	printf_s->str++;
	printf_s->str_pars = printf_s->str;
	while (!ft_strchr("duixXspcn%feg", *printf_s->str))
		printf_s->str++;
	printf_s->arg->type = *printf_s->str;
	printf_s->str = printf_s->str_pars;
	ft_find_flags(printf_s);
	if (ft_strchr_printf("123456789*", *printf_s->str))
		ft_find_width(printf_s);
	if (*printf_s->str == '.')
		ft_find_accu_value(printf_s);
	ft_find_conv(printf_s);
	printf_s->str++;
	if (!printf_s->arg->conv)
		node_to_functions(printf_s);
	else if (printf_s->arg->conv == 'l')
		l_node_to_functions(printf_s);
	else if (printf_s->arg->conv == 'L')
		ll_node_to_functions(printf_s);
	else if (printf_s->arg->conv == 'h')
		h_node_to_functions(printf_s);
	else if (printf_s->arg->conv == 'H')
		hh_node_to_functions(printf_s);
}
