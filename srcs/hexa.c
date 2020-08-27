/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:49:47 by magostin          #+#    #+#             */
/*   Updated: 2020/08/21 03:36:25 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_sizenbr_hexa(long int number)
{
	int			size_nbr;
	long int	n;

	n = number;
	size_nbr = 1;
	n = n < 0 ? -n : n;
	while ((n = n / 16) > 0)
		size_nbr++;
	return (size_nbr);
}

void				ft_hexa_zero(long int n, t_pf *printf_s, int letter)
{
	int		i;
	t_arg	*arg;
	char	*base;

	base = printf_s->arg->type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	arg = printf_s->arg;
	i = -1;
	letter += ft_sizenbr_hexa(n) > arg->accu_value
	? ft_sizenbr_hexa(n) : arg->accu_value;
	while (++i < arg->width - letter)
		ft_putchar('0', printf_s);
	ft_puthexa(n, base, 16, printf_s);
}

void				ft_hexa_none(long int n, t_pf *printf_s, int letter)
{
	int		i;
	t_arg	*arg;
	char	*base;

	base = printf_s->arg->type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	arg = printf_s->arg;
	i = -1;
	letter += ft_sizenbr_hexa(n) > arg->accu_value
	? ft_sizenbr_hexa(n) : arg->accu_value;
	while (++i < arg->width - letter)
		ft_putchar(' ', printf_s);
	i = -1;
	while (++i < arg->accu_value - ft_sizenbr_hexa(n))
		ft_putchar('0', printf_s);
	ft_puthexa(n, base, 16, printf_s);
}

void				ft_hexa_minus(long int n, t_pf *printf_s, int letter)
{
	int		i;
	t_arg	*arg;
	char	*base;

	base = printf_s->arg->type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	arg = printf_s->arg;
	i = -1;
	while (++i < arg->accu_value - ft_sizenbr_hexa(n))
		ft_putchar('0', printf_s);
	ft_puthexa(n, base, 16, printf_s);
	i = -1;
	letter += ft_sizenbr_hexa(n) > arg->accu_value
	? ft_sizenbr_hexa(n) : arg->accu_value;
	while (++i < arg->width - letter)
		ft_putchar(' ', printf_s);
}

void				ft_hexa_function(long int n, t_pf *printf_s)
{
	int		letter;
	t_arg	*arg;

	arg = printf_s->arg;
	letter = 0;
	if (*printf_s->str_pars == '0'
	&& *(printf_s->str - 2) == '*' && arg->accu_value < 0 && arg->flags != '-')
		arg->flags = '0';
	if (arg->flags == '-')
		ft_hexa_minus(n, printf_s, letter);
	else if (arg->flags == '0')
		ft_hexa_zero(n, printf_s, letter);
	else
		ft_hexa_none(n, printf_s, letter);
}
