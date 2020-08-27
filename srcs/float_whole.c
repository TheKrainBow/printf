/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_whole.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 01:58:43 by magostin          #+#    #+#             */
/*   Updated: 2020/08/25 14:19:36 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		clear_entier(long double f)
{
	int			i;

	i = 1048576 * 2;
	while (i > 2)
	{
		while (f > ((long double)INT_MAX * i))
			f -= ((long double)INT_MAX * i);
		i /= 2;
	}
	while (f > ((long double)INT_MAX))
		f -= ((long double)INT_MAX);
	f -= (long double)(int)f;
	return (f);
}

int				get_nbr(long double f, int n)
{
	int			i;

	i = -1;
	while (++i < n)
		f /= 10;
	f = clear_entier(f);
	f *= 10;
	return ((int)f);
}

void			ft_print_whole(long double f, t_pf *printf_s)
{
	long double		f_temp;
	int				i;

	if (f < 0)
	{
		ft_putchar('-', printf_s);
		f *= -1;
	}
	if ((int)f == 0)
	{
		ft_putchar('0', printf_s);
		return ;
	}
	i = 0;
	f_temp = f;
	while ((int)f != 0)
	{
		f /= 10;
		i++;
	}
	while (i > 0)
	{
		ft_putchar(get_nbr(f_temp, i) + '0', printf_s);
		i--;
	}
}
