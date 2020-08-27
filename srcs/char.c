/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:36:33 by magostin          #+#    #+#             */
/*   Updated: 2020/08/25 14:18:03 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_putchar(char c, t_pf *printf_s)
{
	write(1, &c, 1);
	printf_s->n_c++;
}

void				ft_char_function(long long int n, t_pf *printf_s)
{
	int		i;
	t_arg	*arg;

	arg = printf_s->arg;
	i = -1;
	if (arg->width < 0)
	{
		arg->flags = '-';
		arg->width *= -1;
	}
	if (arg->flags == '-')
		ft_putchar(n, printf_s);
	while (++i < arg->width - 1)
		ft_putchar(arg->flags == '0' ? '0' : ' ', printf_s);
	if (arg->flags != '-')
		ft_putchar(n, printf_s);
}
