/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:29 by ggilbert          #+#    #+#             */
/*   Updated: 2021/02/04 20:07:16 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_extention(char *av, const char *ext)
{
	int		i;
	size_t	ext_len;

	i = 0;
	ext_len = ft_strlen(ext);
	while (av[i] != '\0')
		i++;
	while (av[i] != '.' || i == 0)
		i--;
	if (ft_strncmp(&av[i], ext, ext_len))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_parameters	params;

	params.age = 12;
	if (ac == 2 || (ac == 3 && !ft_strncmp(av[2], "--save", 6)))
	{
		if (!check_file_extention(av[1], ".cub"))
		{
			ft_putstr_fd("Error : provide file must be a .cub file", 1);
			return (-1);
		}
		printf("GREAT");
	}
	else
	{
		ft_putstr_fd("Error : Bad number of arguments\n\
\tFirst must be .cub file\n\
\tSecond (optional) must be --save\n", 1);
		return (-1);
	}
	return (1);
}
