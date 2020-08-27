/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:42:52 by magostin          #+#    #+#             */
/*   Updated: 2020/08/25 14:19:42 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_float_recu(long double n, int i, t_pf *printf_s, int round[2])
{
	if (i == printf_s->arg->accu_value)
		return (-1);
	if ((i < printf_s->arg->accu_value && printf_s->arg->type != 'g')
	|| (i < printf_s->arg->accu_value - round[1] && printf_s->arg->type == 'g'))
	{
		if (i < round[0])
			ft_putchar((int)(n * 10) + '0', printf_s);
		else
			ft_putchar(((int)(n * 10) + 1) == 10 ? '0' :
			((int)(n * 10) + 1) + '0', printf_s);
	}
	ft_float_recu((n * 10) - (double)(int)(n * 10), i + 1, printf_s, round);
	return (1);
}

void		init_float_struct(t_float *s_f, long double n, t_pf *printf_s)
{
	(void)s_f;
	(void)n;
	(void)printf_s;
	s_f->temp = n;
	s_f->temp_int = (long int)n;
	s_f->round = printf_s->arg->accu_value;
	s_f->zero = 0;
	return ;
}

void		get_zero(long double n, t_float *s_f, t_pf *printf_s)
{
	s_f->zero = 0;
	s_f->j = -1;
	while (++s_f->j <= printf_s->arg->accu_value)
	{
		s_f->i = -1;
		s_f->temp = n;
		while (++s_f->i < printf_s->arg->accu_value - s_f->j - 1)
		{
			s_f->temp *= 10;
			s_f->temp = clear_entier(s_f->temp);
		}
		if ((int)(s_f->temp * 10) == 0 || ((int)(s_f->temp * 10) == 9
		&& (int)(s_f->temp * 100) >= 5))
		{
			s_f->zero = s_f->zero + 1;
		}
		else
			break ;
	}
}

void		get_round(long double n, t_float *s_f, t_pf *printf_s)
{
	s_f->j = -1;
	s_f->round = printf_s->arg->accu_value;
	while (++s_f->j <= printf_s->arg->accu_value)
	{
		s_f->i = -1;
		s_f->temp = n;
		while (++s_f->i < printf_s->arg->accu_value - s_f->j)
		{
			s_f->temp *= 10;
			s_f->temp = clear_entier(s_f->temp);
		}
		if ((int)(s_f->temp * 10) >= ((s_f->j == 0) ? 5 : 9))
			s_f->round--;
		else
			break ;
	}
}

void		ft_float_print(long double n, t_pf *printf_s)
{
	t_float		*s_f;
	int			round[2];
	long double	temp;

	s_f = printf_s->s_float;
	temp = n;
	n = n < 0 ? -n : n;
	n = clear_entier(n);
	get_round(n, s_f, printf_s);
	if (printf_s->arg->accu_value == 0 && !((int)(n * 10) >= 5))
		s_f->round++;
	if (n == 0 && s_f->temp_int == 0 && !printf_s->arg->accu_value)
		ft_putchar('0', printf_s);
	ft_print_whole((s_f->round == -1) ? temp
	+ 1 : temp, printf_s);
	if ((printf_s->arg->accu_value > 0 && printf_s->arg->type != 'g') ||
	(s_f->zero < printf_s->arg->accu_value && printf_s->arg->type == 'g'
	&& printf_s->arg->accu_value > 0))
		ft_putchar('.', printf_s);
	round[0] = s_f->round;
	round[1] = s_f->zero;
	ft_float_recu(n, 0, printf_s, round);
}
