/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:52:18 by magostin          #+#    #+#             */
/*   Updated: 2020/08/21 03:36:29 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_n_zero(long long int n, t_pf *printf_s, int letter)
{
	int		i;
	t_arg	*arg;

	arg = printf_s->arg;
	i = -1;
	letter += ft_sizenbr(n, 10) > arg->accu_value
	? ft_sizenbr(n, 10) : arg->accu_value;
	while (++i < arg->width - letter)
		ft_putchar('0', printf_s);
	ft_putnbrbase(n, "0123456789", printf_s);
}

void				ft_n_none(long long int n, t_pf *printf_s, int letter)
{
	int		i;
	t_arg	*arg;

	arg = printf_s->arg;
	i = -1;
	letter += ft_sizenbr(n, 10) > arg->accu_value
	? ft_sizenbr(n, 10) : arg->accu_value;
	while (++i < arg->width - (n < 0 ? letter + 1 : letter))
		ft_putchar(' ', printf_s);
	if (n < 0)
		ft_putchar('-', printf_s);
	i = -1;
	while (++i < arg->accu_value - ft_sizenbr(n, 10))
		ft_putchar('0', printf_s);
	ft_putnbrbase(n, "0123456789", printf_s);
}

void				ft_n_minus(long long int n, t_pf *printf_s, int letter)
{
	int		i;
	t_arg	*arg;

	arg = printf_s->arg;
	i = -1;
	while (++i < arg->accu_value - ft_sizenbr(n, 10))
		ft_putchar('0', printf_s);
	ft_putnbrbase(n, "0123456789", printf_s);
	i = -1;
	letter += ft_sizenbr(n, 10) > arg->accu_value
	? ft_sizenbr(n, 10) : arg->accu_value;
	while (++i < arg->width - letter)
		ft_putchar(' ', printf_s);
}

void				ft_number_function(long long int n, t_pf *printf_s)
{
	int		letter;
	t_arg	*arg;

	arg = printf_s->arg;
	letter = 0;
	if (*printf_s->str_pars == '0'
	&& *(printf_s->str - 2) == '*' && arg->accu_value < 0 && arg->flags != '-')
		arg->flags = '0';
	if (n < 0 && arg->flags)
	{
		ft_putchar('-', printf_s);
		letter++;
	}
	if (arg->flags == '-')
		ft_n_minus(n, printf_s, letter);
	else if (arg->flags == '0')
		ft_n_zero(n, printf_s, letter);
	else
		ft_n_none(n, printf_s, letter);
}
