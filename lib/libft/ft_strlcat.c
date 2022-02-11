/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:13:02 by ggilbert          #+#    #+#             */
/*   Updated: 2019/10/23 09:24:56 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srcl;
	size_t	dstl;

	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	if (dstsize > dstl)
	{
		while (*dst)
		{
			dst++;
			dstsize--;
		}
		while (*src && dstsize-- > 1)
		{
			*dst = *src;
			dst++;
			src++;
		}
		*dst = '\0';
		return (srcl + dstl);
	}
	else
		return (srcl + dstsize);
}
