/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:02:42 by ggilbert          #+#    #+#             */
/*   Updated: 2019/10/23 18:26:55 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;
	unsigned int	i;

	if (!dst && !src)
		return (0);
	pd = (unsigned char *)dst;
	ps = (unsigned char *)src;
	i = 0;
	if (ps < pd)
		while (len-- > 0)
			pd[len] = ps[len];
	else
	{
		while (i < len)
		{
			pd[i] = ps[i];
			i++;
		}
	}
	return (dst);
}
