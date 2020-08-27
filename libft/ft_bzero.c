/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 01:36:36 by magostin          #+#    #+#             */
/*   Updated: 2019/11/11 04:45:06 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*temp;

	temp = s;
	i = 0;
	while (i < (int)n)
	{
		temp[i] = 0;
		i++;
	}
	s = temp;
}
