/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:53:57 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/03 17:48:28 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_str_is_digitspace(char *str)
{
	while (*str != '\0')
	{
		if (!ft_isdigit(*str) && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}

char	**check_number_param(size_t nb_par, char *line, char split)
{
	size_t			splitted_l;
	char			**splitted;

	splitted_l = 0;
	splitted = ft_split(++line, split);
	splitted_l = ft_splitted_length(splitted);
	if (splitted_l != nb_par)
	{
		ft_split_free((void **)splitted);
		return (NULL);
	}
	return (splitted);
}
