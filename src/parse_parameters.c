/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:36:52 by ggilbert          #+#    #+#             */
/*   Updated: 2021/03/08 10:51:47 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 ** Je devrai parser l'ensemble et vérifier ensuite s'il y a des erreurs
 */

void				parse_res(t_params *params, char *line)
{
	unsigned int	max_x;
	unsigned int	max_y;
	int				i;
	char			**splitted;

	max_x = 1920;
	max_y = 1080;
	i = 0;
	splitted = ft_split(++line, ' ');
	while (splitted[i] != NULL)
		i++;
	if (i != 2)
		error_init("Resolution must have 2 values");
	printf("LOL %d %d", params->res_x, params->res_y);
	/*if (params->res_x != 0 || params->res_x != 0)//preter attention
		error_init("Resolution initialise multiple times.");*/
	params->res_x = ft_atoi(splitted[0]);
	params->res_y = ft_atoi(splitted[1]);
	params->res_x > max_x ? params->res_x = max_x : params->res_x;
	params->res_y > max_y ? params->res_y = max_y : params->res_y;
	printf("%d, %d\n", params->res_x, params->res_y);
	ft_split_free((void **)splitted);
	params->nb_valid_param++;
}

void				parse_color(t_params *params, char *line)
{
	ft_putstr_fd("Ici parse_color\n", 1);
	params->nb_valid_param++;
	(void)line;
}

void				parse_text_path(t_params *params, char *line)
{
	ft_putstr_fd("Ici parse_text_path\n", 1);
	params->nb_valid_param++;
	(void)line;
}
