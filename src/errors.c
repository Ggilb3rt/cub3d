/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:41:23 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/10 11:10:55 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_errs(int ac, char **av, t_params *params,
	t_player *player, t_map *map)
{
	if (MOVE_SPEED > 1)
	{
		printf("Cannot go too fast\n");
		exit(1);
	}
	if (ac == 2)
	{
		if (err_in_file(av, params, player, map))
			exit(0);
	}
	else
		ft_exit("Bad number of arguments\n");
}

char	**init_tab_err(void)
{
	char	**tab;

	tab = malloc(sizeof(tab) * 14);
	tab[0] = ft_strdup("Can't read next line");
	tab[1] = ft_strdup("Crash of malloc");
	tab[2] = ft_strdup("Find invalid parameter or same multiple times");
	tab[3] = ft_strdup("Invalid quantity of parameters");
	tab[4] = ft_strdup("Provided file must be a .cub file");
	tab[5] = ft_strdup("Find somthing wrong in the map.");
	tab[6] = ft_strdup("Invalid quantity of values in parameter");
	tab[7] = ft_strdup("Invalid type of value in parameter");
	tab[8] = ft_strdup("Texture path must start with \"./\" and be xpm file");
	tab[9] = ft_strdup("Invalid ceiling or floor color value [0 - 255]");
	tab[10] = ft_strdup("Unknow char in map");
	tab[11] = ft_strdup("Hole in map");
	tab[12] = ft_strdup("It's a single player game");
	tab[13] = NULL;
	return (tab);
}

void	print_error(int err_nb)
{
	char	**tab_err;

	tab_err = init_tab_err();
	ft_putstr_fd("ERROR : \n", 1);
	ft_putstr_fd(tab_err[err_nb], 1);
	ft_putstr_fd("\n", 1);
	ft_split_free((void **)tab_err);
}

void	ft_exit(char *context)
{
	ft_putstr_fd(context, 1);
	ft_putstr_fd("\n", 1);
	exit(0);
}
