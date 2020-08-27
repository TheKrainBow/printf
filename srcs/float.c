/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:34:46 by magostin          #+#    #+#             */
/*   Updated: 2020/08/27 18:12:32 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_g_function(long double n, t_pf *printf_s)
{
	int			exp;

	printf_s->s_float->neg = n < 0 ? 1 : 0;
	n = n < 0 ? -n : n;
	exp = get_exp(n);
	if (!printf_s->arg->accu)
	{
		printf_s->arg->accu = 1;
		printf_s->arg->accu_value = 6;
	}
	if (printf_s->arg->accu_value == 0)
		printf_s->arg->accu_value++;
	if (printf_s->arg->accu_value > exp && exp >= -4)
	{
		printf_s->arg->accu_value = printf_s->arg->accu_value - 1 - exp;
		ft_float_function(n, printf_s);
		return ;
	}
	else
	{
		printf_s->arg->accu_value = printf_s->arg->accu_value - 1;
		ft_sc_function(n, printf_s);
	}
}

void			ft_expo_print(int exp, t_pf *printf_s)
{
	ft_putchar('e', printf_s);
	ft_putchar(exp < 0 ? '-' : '+', printf_s);
	if (exp < 9 && exp > -9)
		ft_putchar('0', printf_s);
	if (exp == 0)
		ft_putchar('0', printf_s);
	else
		ft_putnbrbase(exp, "0123456789", printf_s);
}

void			ft_blanks(long double n, int exp, t_pf *printf_s)
{
	int		i;

	i = -1;
	while (++i < printf_s->arg->width - (ft_sizenbr((int)n, 10) +
	((printf_s->arg->accu_value) > 0 ? 1 : 0) + printf_s->arg->accu_value + 2 +
	((exp < 9 && exp > -9) ? 1 : 0) + ft_sizenbr(exp, 10))
	- printf_s->s_float->neg)
		ft_putchar(printf_s->arg->zero == 0 ? ' ' : '0', printf_s);
}

void			ft_sc_function(long double n, t_pf *printf_s)
{
	int			exp;

	printf_s->s_float->neg = n < 0 ? 1 : 0;
	n = n < 0 ? -n : n;
	exp = get_exp(n);
	if (!printf_s->arg->accu)
	{
		printf_s->arg->accu = 1;
		printf_s->arg->accu_value = 6;
	}
	printf_s->arg->zero = printf_s->arg->flags != '0' ? 0 : 1;
	if (printf_s->arg->flags != 0 && printf_s->s_float->neg == 1)
		ft_putchar('-', printf_s);
	if (printf_s->arg->flags != '-')
		ft_blanks(n, exp, printf_s);
	if (printf_s->arg->flags == 0 && printf_s->s_float->neg == 1)
		ft_putchar('-', printf_s);
	ft_float_print(n, printf_s);
	ft_expo_print(exp, printf_s);
	if (printf_s->arg->flags == '-')
		ft_blanks(n, exp, printf_s);
}

void			ft_float_function(long double n, t_pf *printf_s)
{
	long int	letter;

	init_float_struct(printf_s->s_float, n, printf_s);
	if (!printf_s->arg->accu)
		printf_s->arg->accu_value = 6;
	if (!printf_s->arg->accu)
		printf_s->arg->accu = 1;
	printf_s->s_float->neg = n < 0 ? 1 : 0;
	n = n < 0 ? -n : n;
	get_zero(clear_entier(n), printf_s->s_float, printf_s);
	letter = ft_sizenbr((int)n, 10) + ((printf_s->arg->accu_value) > 0 ? 1 : 0)
	+ printf_s->arg->accu_value + (printf_s->s_float->neg == 1 ? 1 : 0);
	if ((printf_s->arg->flags != 0 && printf_s->s_float->neg == 1) ||
	(printf_s->arg->zero == 1 && printf_s->s_float->neg == 1
	&& printf_s->arg->type == 'g'))
		ft_putchar('-', printf_s);
	if (printf_s->arg->flags != '-')
		ft_float_blanks(letter, printf_s);
	if (printf_s->arg->flags == 0 && ft_float_test(printf_s))
		ft_putchar('-', printf_s);
	ft_float_print(n, printf_s);
	if (printf_s->arg->flags == '-')
		ft_float_blanks(letter, printf_s);
}
