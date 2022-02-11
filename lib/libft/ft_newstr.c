/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:52:52 by ggilbert          #+#    #+#             */
/*   Updated: 2021/02/04 19:13:37 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_newstr(size_t size)
{
	char	*str;

	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (0);
	while ((int)size-- >= 0)
		*(str + size + 1) = '\0';
	return (str);
}
