/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjarhbou <yjarhbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:45:05 by yjarhbou          #+#    #+#             */
/*   Updated: 2022/06/21 21:50:48 by yjarhbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img(t_map *map, int i, int j, void *img_ptr)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, \
	img_ptr, j * PICTURESIZE, i * PICTURESIZE);
}

void	show_moves(t_map *map)
{
	char	str[10];

	sprintf(str, "%d", map->steps);
	map->texture_black = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/just_black.xpm", &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->mlx_win, \
	map->texture_black, 0, 0);
	mlx_string_put(map->mlx, map->mlx_win, 2, 2, 0xffc94277, "Moves: ");
	mlx_string_put(map->mlx, map->mlx_win, 70, 2, 0xffc94277, str);
}

void	map_render(t_map *map, int i, int j)
{
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->field[i][j] == '1')
				put_img(map, i, j, map->texture_wall);
			else
			{
				put_img(map, i, j, map->texture_floor);
				if (map->field[i][j] == 'P')
					put_img(map, i, j, map->texture_mouse);
				else if (map->field[i][j] == 'C')
					put_img(map, i, j, map->texture_cheese);
				else if (map->field[i][j] == 'E')
					put_img(map, i, j, map->texture_exit);
				else if (map->field[i][j] == 'T')
					put_img(map, i, j, map->texture_trap);
			}
		}
	}
	show_moves(map);
}

void	game_init(t_map *map)
{
	map->texture_mouse = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/mouse1.xpm", &map->img_width, &map->img_height);
	map->texture_trap = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/trap.xpm", &map->img_width, &map->img_height);
	map->texture_exit = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/mouse_house.xpm", &map->img_width, &map->img_width);
	map->texture_floor = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/floor.xpm", &map->img_width, &map->img_height);
	map->texture_wall = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/wall.xpm", &map->img_width, &map->img_height);
	map->texture_cheese = mlx_xpm_file_to_image(map->mlx, \
	"Bonus/Xpms/cheese.xpm", &map->img_width, &map->img_height);
	if (!map->texture_mouse || !map->texture_exit || !map->texture_floor \
		|| !map->texture_wall || !map->texture_cheese || !map->texture_trap)
	{
		perror("Error with xpm files");
		free (map->field);
		exit(EXIT_FAILURE);
	}
	map_render(map, -1, -1);
}
