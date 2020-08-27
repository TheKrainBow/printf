/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 03:34:20 by magostin          #+#    #+#             */
/*   Updated: 2019/11/14 22:40:57 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char buff[len];

	if (dst == NULL && src == NULL)
		return (NULL);
	ft_memcpy(buff, src, len);
	ft_memcpy(dst, buff, len);
	return (dst);
}
