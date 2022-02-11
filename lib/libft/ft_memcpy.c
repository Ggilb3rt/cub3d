/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:51:39 by ggilbert          #+#    #+#             */
/*   Updated: 2019/10/23 09:17:08 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (0);
	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	while (n > i)
	{
		*pdst = *psrc;
		pdst++;
		psrc++;
		i++;
	}
	return (dst);
}
