/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:29:18 by magostin          #+#    #+#             */
/*   Updated: 2020/08/25 14:30:09 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_float_blanks(long int letter, t_pf *printf_s)
{
	int			i;

	i = -1;
	while ((++i < printf_s->arg->width - letter && printf_s->arg->type == 'f')
	|| ((i <= (printf_s->arg->width - letter + printf_s->s_float->zero - 1) &&
	printf_s->arg->type == 'g')))
		ft_putchar(printf_s->arg->zero == 0 ? ' ' : '0', printf_s);
}

int				ft_float_test(t_pf *printf_s)
{
	return (printf_s->s_float->neg == 1 &&
	!(printf_s->arg->zero == 1 && printf_s->s_float->neg == 1
	&& printf_s->arg->type == 'g'));
}
