/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:48:03 by magostin          #+#    #+#             */
/*   Updated: 2019/11/17 20:36:47 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst && f)
	{
		temp = lst->next;
		f(lst->content);
		if (temp)
		{
			while (temp != NULL)
			{
				temp = lst->next;
				f(lst->content);
				lst = temp;
			}
		}
	}
}
