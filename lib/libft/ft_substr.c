/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:02:32 by ggilbert          #+#    #+#             */
/*   Updated: 2019/10/17 13:26:25 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;

	c = malloc(len * sizeof(*c) + 1);
	if (c == NULL)
		return (0);
	if (!*s || ft_strlen(s) < start)
	{
		c[0] = '\0';
		return (c);
	}
	while (start--)
		s++;
	ft_strlcpy(c, s, len + 1);
	return (c);
}
