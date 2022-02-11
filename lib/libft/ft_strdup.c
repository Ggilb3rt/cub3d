/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:35:30 by ggilbert          #+#    #+#             */
/*   Updated: 2019/10/23 09:38:46 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c;
	size_t	s1l;

	s1l = ft_strlen(s1);
	c = (char *)malloc((s1l + 1) * sizeof(*c));
	if (c == NULL)
		return (0);
	ft_strlcpy(c, s1, s1l + 1);
	return (c);
}
