/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:52:10 by ggilbert          #+#    #+#             */
/*   Updated: 2019/10/18 11:46:18 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else if (*alst && alst)
	{
		lst = *alst;
		new->next = lst;
		*alst = new;
	}
}
