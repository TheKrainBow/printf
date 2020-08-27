/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 01:21:50 by magostin          #+#    #+#             */
/*   Updated: 2019/11/18 21:40:52 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t		dstsize;

	dstsize = ft_strlen(dst);
	if (dstsize > size)
		return (size + ft_strlen(src));
	return (ft_strlcpy(dst + dstsize, src, size - dstsize) + dstsize);
}
