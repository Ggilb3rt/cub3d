/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:29 by ggilbert          #+#    #+#             */
/*   Updated: 2022/02/12 15:03:45 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_print_params(t_params params)
{
	printf("\n\nGAME INFORMATIONS\n*****\n");
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
	size_t	y;

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
		y = 0;
		while (y < map.width && map.map[i][y] != '\0')
		{
			printf("%c", map.map[i][y]);
			y++;
		}
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
	params->path_texture_ea == NULL;
	params->path_texture_no == NULL;
	params->path_texture_so == NULL;
	params->path_texture_we == NULL;
	player->orientation = '0';
	map->height = 0;
	map->width = 0;
	map->rotated = FALSE;
	map->map = NULL;
}

int	err_in_file(char **av, t_params *params, t_player *player, t_map *map)
{
	if (!ft_check_file_extention(av[1], ".cub")
		|| open(av[1], O_DIRECTORY) != -1)
	{
		print_error(e_cub_file);
		return (1);
	}
	if (!parse_root(av[1], params, map, player))
		return (1);
	if (check_params_integrity(params) != -1)
	{
		free_params(params);
		free_map(map);
		return (1);
	}
	if (map_ok_or_quit(map) != -1)
	{
		free_params(params);
		free_map(map);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_base			*base;
	t_params		params;
	t_player		player;
	t_map			map;

	set_zero(&params, &player, &map);
	if (ac == 2)
		handle_errs(av, &params, &player, &map);
	else
		ft_exit("Bad number of arguments\n");
	debug_print_params(params);
	debug_print_map(map, player);
	base = init_base(&params, &map, &player);
	if (base == NULL)
		exit(0);
	mlx_hook(base->win, 17, 1L << 17, close_win, base);
	mlx_hook(base->win, 2, 1L << 0, key_press, base);
	mlx_hook(base->win, 3, 1L << 1, key_release, base);
	put_img(base);
	mlx_loop(base->mlx);
	return (0);
}
