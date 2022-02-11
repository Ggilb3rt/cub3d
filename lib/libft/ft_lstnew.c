/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:05:39 by ggilbert          #+#    #+#             */
/*   Updated: 2019/10/17 17:56:35 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (l == NULL)
		return (NULL);
	if (!content)
	{
		l->content = NULL;
	}
	else
	{
		l->content = malloc(sizeof(*(l->content)) * sizeof(content));
		if (l->content == NULL)
			return (NULL);
		l->content = content;
	}
	l->next = NULL;
	return (l);
}
