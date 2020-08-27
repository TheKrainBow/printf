/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 02:16:40 by magostin          #+#    #+#             */
/*   Updated: 2019/11/14 18:44:34 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*bufferdst;
	unsigned char	*buffersrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	bufferdst = (unsigned char *)dst;
	buffersrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		bufferdst[i] = buffersrc[i];
		i++;
	}
	dst = bufferdst;
	return (dst);
}
