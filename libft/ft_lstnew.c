/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:59:17 by magostin          #+#    #+#             */
/*   Updated: 2019/11/17 20:34:56 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*maillon;

	if (!(maillon = (t_list*)malloc(sizeof(t_list))))
		return (0);
	maillon->content = content;
	maillon->next = NULL;
	return (maillon);
}
