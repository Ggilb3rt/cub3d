/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:36:26 by ggilbert          #+#    #+#             */
/*   Updated: 2019/10/22 16:24:04 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;
	t_list	*tmpd;

	if (lst && f && del)
	{
		newlst = ft_lstnew(f(lst->content));
		tmpd = newlst;
		lst = lst->next;
		while (lst)
		{
			tmp = ft_lstnew(f(lst->content));
			if (!tmp)
				del(tmp);
			tmpd->next = tmp;
			tmpd = tmp;
			lst = lst->next;
		}
		return (newlst);
	}
	else
		return (0);
}
