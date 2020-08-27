/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 03:28:04 by magostin          #+#    #+#             */
/*   Updated: 2019/11/17 22:13:56 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*buffer;
	size_t			i;

	i = 0;
	if (!(buffer = (unsigned char *)malloc(count * size)))
		return (0);
	while (i < count * size)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}
