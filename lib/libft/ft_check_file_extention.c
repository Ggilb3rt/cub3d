/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_extention.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:53:42 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/01 16:17:35 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_file_extention(char *av, const char *ext)
{
	int		i;
	size_t	ext_len;

	i = 0;
	ext_len = ft_strlen(ext);
	while (av[i] != '\0')
		i++;
	while (av[i] != '.' && i > 0)
		i--;
	if (ft_strncmp(&av[i], ext, ext_len))
		return (0);
	return (1);
}
