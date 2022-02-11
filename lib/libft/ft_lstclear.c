/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:43:26 by ggilbert          #+#    #+#             */
/*   Updated: 2019/10/22 16:13:56 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*nxt;

	if (*lst && lst && del)
	{
		tmp = *lst;
		while (tmp)
		{
			nxt = tmp->next;
			ft_lstdelone(tmp, del);
			tmp = nxt;
		}
		*lst = 0;
	}
}
