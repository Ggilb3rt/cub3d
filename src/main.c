/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:29 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/02 19:22:49 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_print_params(t_params params)
{
	printf("\n\nREGLAGES INFORMATIONS\n*****\n");
	printf("RESOLUTION : X:%d\tY:%d\n", params.res_x, params.res_y);
	printf("CEILLING COLOR TAB : %d, %d, %d\n",
		params.ceiling_color[0],
		params.ceiling_color[1],
		params.ceiling_color[2]);
	printf("FLOOR COLOR TAB : %d, %d, %d\n",
		params.floor_color[0], params.floor_color[1], params.floor_color[2]);
	printf("PATHS :\n%s\n%s\n%s\n%s",
		params.path_texture_no, params.path_texture_so,
		params.path_texture_ea, params.path_texture_we);
}

void	debug_print_map(t_map map, t_player player)
{
	size_t	i;

	printf("\n\nMAP INFORMATIONS\n******\n");
	printf("Player orientation %c, angle : %f\ndeltaX %f, deltaY %f\n",
		player.orientation, player.angle,
		player.pos_delta_x, player.pos_delta_y);
	printf("pos_x %f, pos_y %f\n", player.pos_x, player.pos_y);
	printf("Map Width %zu\nMap Height %zu\n\nPrint map.map\n",
		map.width, map.height);
	i = 0;
	while (i < map.height)
	{
		//printf("%ld|\t", ft_strlen(map.map[i]));
		for(size_t y = 0; y < map.width && map.map[i][y] != '\0'; y++)
		{
			printf("%c", map.map[i][y]);
		}
		// if (i == player.pos_y)
		// 	printf("\033[0;33m");
		// printf("%s\n", map.map[i]);
		// if (i == player.pos_y)
		// 	printf("\033[0m");
		printf("\n");
		i++;
	}
}

void	set_zero(t_params *params, t_player *player, t_map *map)
{
	params->nb_valid_param = 0;
	params->unique.ceiling = 0;
	params->unique.floor = 0;
	params->unique.resolution = 0;
	params->unique.texture_no = 0;
	params->unique.texture_so = 0;
	params->unique.texture_ea = 0;
	params->unique.texture_we = 0;
	player->orientation = '0';
	map->height = 0;
	map->width = 0;
	map->map = NULL;
}

int	parse(char *av, t_params *params, t_map *map, t_player *player)
{
	int		fd;
	int		ret;

	fd = open(av, O_RDONLY);
	ret = init_param(params, &fd);
	if (ret > -1)
	{
		print_error("param pouet", ret);
		close(fd);
		free_params(params);
		return (0);
	}
	ret = init_map(params, map, player, &fd);
	if (ret > -1)
	{
		print_error("map pouet", ret);
		close(fd);
		free_params(params);
		free_map(map);
		return (0);
	}
	close(fd);
	return (1);
}

int	main(int ac, char **av)
{
	t_params		params;
	t_player		player;
	t_map			map;

	set_zero(&params, &player, &map);
	if (ac == 2 || (ac == 3 && !ft_strncmp(av[2], "--save", 6)))
	{
		if (!ft_check_file_extention(av[1], ".cub"))
		{
			print_error("debut", e_cub_file);
			return (0);
		}
		if (!parse(av[1], &params, &map, &player))
			return (0);
		check_params_integrity(&params);
		check_map_integrity(&map);
	}
	else
		ft_exit("Bad number of arguments\n");
	debug_print_params(params);
	debug_print_map(map, player);
	free_map(&map);
	free_params(&params);
	return (0);
}
