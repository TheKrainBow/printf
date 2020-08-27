/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:51:10 by magostin          #+#    #+#             */
/*   Updated: 2020/08/21 03:36:15 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_sizenbr_ad(long int number)
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

void				ft_ad_zero(long int n, t_pf *printf_s, int letter)
{
	int		i;
	t_arg	*arg;
	char	*base;

	base = "0123456789abcdef";
	arg = printf_s->arg;
	if (arg->accu_value < 0 || arg->accu == 0)
	{
		arg->accu_value = arg->width - 2;
		arg->width = 0;
	}
	i = -1;
	letter += (arg->accu_value == 0 && n == 0 && arg->accu) ? 1 : 2;
	letter += ft_sizenbr_ad(n) > arg->accu_value
	? ft_sizenbr_ad(n) : arg->accu_value;
	while (++i < arg->width - letter)
		ft_putchar(' ', printf_s);
	i = -1;
	ft_putchar('0', printf_s);
	ft_putchar('x', printf_s);
	while (++i < arg->accu_value - ft_sizenbr_ad(n))
		ft_putchar('0', printf_s);
	ft_puthexa(n, base, 16, printf_s);
}

void				ft_ad_none(long int n, t_pf *printf_s, int letter)
{
	int		i;
	t_arg	*arg;
	char	*base;

	base = "0123456789abcdef";
	arg = printf_s->arg;
	i = -1;
	letter += (arg->accu_value == 0 && n == 0 && arg->accu) ? 1 : 2;
	letter += ft_sizenbr_ad(n) > arg->accu_value
	? ft_sizenbr_ad(n) : arg->accu_value;
	while (++i < arg->width - letter)
		ft_putchar(' ', printf_s);
	i = -1;
	ft_putchar('0', printf_s);
	ft_putchar('x', printf_s);
	while (++i < arg->accu_value - ft_sizenbr_ad(n))
		ft_putchar('0', printf_s);
	ft_puthexa(n, base, 16, printf_s);
}

void				ft_ad_minus(long int n, t_pf *printf_s, int letter)
{
	int		i;
	t_arg	*arg;
	char	*base;

	base = "0123456789abcdef";
	arg = printf_s->arg;
	i = -1;
	ft_putchar('0', printf_s);
	ft_putchar('x', printf_s);
	while (++i < arg->accu_value - ft_sizenbr_ad(n))
		ft_putchar('0', printf_s);
	ft_puthexa(n, base, 16, printf_s);
	i = -1;
	letter += ft_sizenbr_ad(n) > arg->accu_value
	? ft_sizenbr_ad(n) : arg->accu_value;
	while (++i < arg->width - letter - 2)
		ft_putchar(' ', printf_s);
}

void				ft_address_function(void *n, t_pf *printf_s)
{
	int		letter;
	t_arg	*arg;

	arg = printf_s->arg;
	letter = 0;
	if (arg->width == 0 && arg->flags != '-' && arg->accu_value != 0)
		arg->flags = '0';
	if (arg->flags == '-')
		ft_ad_minus((long int)n, printf_s, letter);
	else if (arg->flags == '0')
		ft_ad_zero((long int)n, printf_s, letter);
	else
		ft_ad_none((long int)n, printf_s, letter);
}
