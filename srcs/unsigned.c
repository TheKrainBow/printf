/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:50:14 by magostin          #+#    #+#             */
/*   Updated: 2020/08/21 03:36:33 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_sizenbr_u(unsigned long long number)
{
	int			size_nbr;
	long int	n;

	n = number;
	size_nbr = 1;
	while ((n = n / 10) > 0)
		size_nbr++;
	return (size_nbr);
}

void				ft_u_zero(unsigned long long n, t_pf *printf_s, int letter)
{
	int		i;
	t_arg	*arg;
	char	*base;

	base = "0123456789";
	arg = printf_s->arg;
	i = -1;
	letter += ft_sizenbr_u(n) > arg->accu_value
	? ft_sizenbr_u(n) : arg->accu_value;
	while (++i < arg->width - letter)
		ft_putchar('0', printf_s);
	ft_puthexa(n, base, 10, printf_s);
}

void				ft_u_none(unsigned long long n, t_pf *printf_s, int letter)
{
	int		i;
	t_arg	*arg;
	char	*base;

	base = "0123456789";
	arg = printf_s->arg;
	i = -1;
	letter += ft_sizenbr_u(n) > arg->accu_value
	? ft_sizenbr_u(n) : arg->accu_value;
	while (++i < arg->width - letter)
		ft_putchar(' ', printf_s);
	i = -1;
	while (++i < arg->accu_value - ft_sizenbr_u(n))
		ft_putchar('0', printf_s);
	ft_puthexa(n, base, 10, printf_s);
}

void				ft_u_minus(unsigned long long n, t_pf *printf_s, int letter)
{
	int		i;
	t_arg	*arg;
	char	*base;

	base = "0123456789";
	arg = printf_s->arg;
	i = -1;
	while (++i < arg->accu_value - ft_sizenbr_u(n))
		ft_putchar('0', printf_s);
	ft_puthexa(n, base, 10, printf_s);
	i = -1;
	letter += ft_sizenbr_u(n) > arg->accu_value
	? ft_sizenbr_u(n) : arg->accu_value;
	while (++i < arg->width - letter)
		ft_putchar(' ', printf_s);
}

void				ft_unsigned_function(unsigned long long n, t_pf *printf_s)
{
	int		letter;
	t_arg	*arg;

	arg = printf_s->arg;
	letter = 0;
	if (*printf_s->str_pars == '0'
	&& *(printf_s->str - 2) == '*' && arg->accu_value < 0 && arg->flags != '-')
		arg->flags = '0';
	if (arg->flags == '-')
		ft_u_minus(n, printf_s, letter);
	else if (arg->flags == '0')
		ft_u_zero(n, printf_s, letter);
	else
		ft_u_none(n, printf_s, letter);
}
