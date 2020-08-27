/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:51:33 by magostin          #+#    #+#             */
/*   Updated: 2019/11/17 20:35:31 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *maillon;

	if (!alst || !new)
		return ;
	maillon = *alst;
	if (!maillon)
	{
		*alst = new;
		return ;
	}
	while (maillon->next != NULL)
		maillon = maillon->next;
	maillon->next = new;
	new->next = NULL;
}
