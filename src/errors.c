/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:41:23 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/02 19:31:52 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**init_tab_err(void)
{
	char	**tab;

	tab = malloc(sizeof(tab) * 11);
	tab[0] = ft_strdup(ERR_GNL);
	tab[1] = ft_strdup(ERR_MALLOCCRASH);
	tab[2] = ft_strdup("Find invalid parameter");
	tab[3] = ft_strdup("Invalid quantity of parameters");
	tab[4] = ft_strdup("Provided file must be a .cub file");
	tab[5] = ft_strdup("Find somthing wrong in the map.");
	tab[6] = ft_strdup("Invalid quantity of values in parameter");
	tab[7] = ft_strdup("Invalid type of value in parameter");
	tab[8] = ft_strdup("Texture path must start with \"./\"");
	tab[9] = ft_strdup("Find parameter multiple times");
	tab[10] = NULL;
	return (tab);
}

void	print_error(char *context, int err_nb)
{
	char	**tab_err;

	tab_err = init_tab_err();
	printf("old %s\n", context);
	ft_putstr_fd("ERROR : \n", 1);
	ft_putstr_fd(tab_err[err_nb], 1);
	ft_putstr_fd("\n", 1);
	ft_split_free((void **)tab_err);
}

void	ft_exit(char *context)
{
	//print_error(context, 0);
	ft_putstr_fd(context, 1);
	ft_putstr_fd("\n");
	exit(0);
}
