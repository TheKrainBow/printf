/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:32:17 by magostin          #+#    #+#             */
/*   Updated: 2020/08/25 13:33:56 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_n_function(long long int *n, t_pf *printf_s)
{
	*n = printf_s->n_c;
}

char			*ft_strchr_printf(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c && !ft_strchr("xXdiuscpf%eg", s[i]))
		i++;
	if (s[i] == c)
		return ((char *)(&s[i]));
	return (0);
}

int				get_exp(long double temp)
{
	int		exp;

	exp = 0;
	temp = temp < 0 ? -temp : temp;
	while ((int)(temp) > 9 || (int)temp == INT_MIN)
	{
		temp /= 10;
		exp++;
	}
	while ((int)(temp) <= 0 && temp)
	{
		temp = temp * 10;
		exp--;
	}
	return (exp);
}
