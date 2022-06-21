/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjarhbou <yjarhbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:35:35 by yjarhbou          #+#    #+#             */
/*   Updated: 2022/06/21 21:56:24 by yjarhbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ext(char *fname)
{
	int		i;
	char	*ext;

	i = 0;
	while (fname[i])
		i++;
	ext = &(*(fname + i - 4));
	i = 0;
	if (ext[0] == '.' && ext[1] == 'b' \
		&& ext[2] == 'e' && ext[3] == 'r')
		return ;
	else
		ft_perror("Error\nPlease Recheck the file extension!", 1);
}

void	map_init(t_map *map)
{
	map->player = 0;
	map->collect = 0;
	map->exit = 0;
	map->height = 0;
	map->width = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->moves = 0;
}

void	ft_perror(char *s, int x)
{
	write(2, s, ft_strlen(s));
	write(2, "\n", 2);
	exit(x);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;

	if (ac == 2)
	{
		check_ext(av[1]);
		fd = open (av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_perror("Error while opening the map file", 1);
			exit(EXIT_FAILURE);
		}
		map_init(&map);
		valid_map(&map, fd, av[1]);
		map.mlx = mlx_init();
		map.mlx_win = mlx_new_window(map.mlx, map.width * PICTURESIZE, \
		map.height * PICTURESIZE, "So_long");
		game_init(&map);
		mlx_hook(map.mlx_win, 17, 0, destroy_window, &map);
		mlx_hook(map.mlx_win, 2, (1L << 0), key_hook, &map);
		mlx_loop(map.mlx);
		free(map.mlx);
	}
	ft_perror("this is how to use it:\n ./so_long some_map.ber", 1);
}
