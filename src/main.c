/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:29 by ggilbert          #+#    #+#             */
/*   Updated: 2021/03/25 12:01:10 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_params		params;
	t_player		player;
	t_map			map;
	//t_parser_valid	valid;
	int				fd;

	params.nb_valid_param = 0;
	player.orientation = '0';
	map.height = 0;
	map.width = 0;
	map.map = NULL;
	if (ac == 2 || (ac == 3 && !ft_strncmp(av[2], "--save", 6)))
	{
		if (!ft_check_file_extention(av[1], ".cub"))
		{
			ft_putstr_fd("Error : provide file must be a .cub file", 1);
			return (-1);
		}
		fd = open(av[1], O_RDONLY);
		printf("\nHELLO %s\nFD : %d\n", av[1], fd);
		init_param(&params, &fd);
		init_map(&params, &map, &player, &fd);
	}
	else
		ft_exit("Bad number of arguments\n");

	printf("\n\nREGLAGES INFORMATIONS\n*****\n");
	printf("RESOLUTION :\nX:%d\tY:%d\n", params.res_x, params.res_y);
	printf("CEILLING COLOR TAB : %d, %d, %d\n", params.ceiling_color[0], params.ceiling_color[1], params.ceiling_color[2]);
	printf("FLOOR COLOR TAB : %d, %d, %d\n", params.floor_color[0], params.floor_color[1], params.floor_color[2]);
	printf("PATHS :\n%s\n%s\n%s\n%s\n%s", params.path_texture_sp, params.path_texture_no, params.path_texture_so, params.path_texture_ea, params.path_texture_we);

	printf("\n\nMAP INFORMATIONS\n******\n");
	printf("Player orientation %c, pos_x %f, pos_y %f\n", player.orientation, player.pos_x, player.pos_y);
	printf("Map Width %zu\nMap Height %zu\n\nPrint map.map\n", map.width, map.height);
	for (size_t i = 0; i < map.height; i++)
	{
		if (i == player.pos_y)
			printf("\033[0;31m");
		printf("%s\n", map.map[i]);
		if (i == player.pos_y)
			printf("\033[0m");
		free(map.map[i]);
	}
	free(map.map);
	map.map = NULL;
	/*while(1)
	;*/
	return (1);
}
