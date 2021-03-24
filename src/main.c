/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:08:29 by ggilbert          #+#    #+#             */
/*   Updated: 2021/03/24 16:52:14 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int	check_file_extention(char *av, const char *ext)
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
}*/

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
		ft_exit("Bad number of arguments\nEx : file.cub --save (optional)");
	printf("\nPlayer orientation %c, pos_x %f, pos_y %f\n", player.orientation, player.pos_x, player.pos_y);
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
