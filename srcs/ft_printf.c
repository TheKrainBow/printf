/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:00:22 by magostin          #+#    #+#             */
/*   Updated: 2020/08/21 03:27:32 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_struct(t_pf *s, int oui)
{
	if (!oui)
		return ;
	printf("\naccu: %d\n", s->arg->accu);
	printf("accu_value: %ld\n", s->arg->accu_value);
	printf("width: %d\n", s->arg->width_exist);
	printf("width_value: %ld\n", s->arg->width);
}

void				init_struct(t_pf *printf_s, char *str)
{
	printf_s->str = str;
	printf_s->arg->type = 0;
	printf_s->arg->zero = 0;
	printf_s->arg->flags = 0;
	printf_s->arg->width_exist = 0;
	printf_s->arg->width = 0;
	printf_s->arg->accu = 0;
	printf_s->arg->accu_value = 0;
	printf_s->arg->conv = 0;
	printf_s->error = 0;
}

int					ft_printf(const char *str, ...)
{
	t_pf		printf_s;
	t_arg		arg;
	t_float		s_f;
	va_list		ap;

	va_start(ap, str);
	printf_s.ap = &ap;
	printf_s.s_float = &s_f;
	printf_s.arg = &arg;
	printf_s.n_c = 0;
	init_struct(&printf_s, (char *)str);
	while (*printf_s.str && printf_s.error == 0)
	{
		if (*printf_s.str == '%')
			ft_parsing(&printf_s);
		else
		{
			ft_putchar(*printf_s.str, &printf_s);
			printf_s.str++;
		}
	}
	return (printf_s.error ? -1 : printf_s.n_c);
}
