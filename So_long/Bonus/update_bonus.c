/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjarhbou <yjarhbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:45:32 by yjarhbou          #+#    #+#             */
/*   Updated: 2022/06/21 21:51:20 by yjarhbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	file_to_img(t_map *map, char *file)
{
	map->texture_mouse = mlx_xpm_file_to_image(map->mlx, \
	file, &map->img_width, &map->img_height);
}

void	mouse_right_update(t_map *map)
{
	if (map->count >= 0)
		file_to_img(map, "Bonus/Xpms/mouse1.xpm");
	if (map->count >= 10)
		file_to_img(map, "Bonus/Xpms/mouse2.xpm");
	if (map->count >= 20)
		file_to_img(map, "Bonus/Xpms/mouse3.xpm");
	if (map->count >= 30)
		file_to_img(map, "Bonus/Xpms/mouse4.xpm");
	if (map->count >= 40)
		file_to_img(map, "Bonus/Xpms/mouse5.xpm");
	if (map->count >= 50)
		file_to_img(map, "Bonus/Xpms/mouse6.xpm");
	if (map->count >= 60)
		file_to_img(map, "Bonus/Xpms/mouse7.xpm");
	if (map->count >= 70)
		file_to_img(map, "Bonus/Xpms/mouse8.xpm");
	if (map->count >= 80)
		file_to_img(map, "Bonus/Xpms/mouse9.xpm");
}

void	mouse_left_update(t_map *map)
{
	if (map->count >= 0)
		file_to_img(map, "Bonus/Xpms/mouse_left1.xpm");
	if (map->count >= 10)
		file_to_img(map, "Bonus/Xpms/mouse_left2.xpm");
	if (map->count >= 20)
		file_to_img(map, "Bonus/Xpms/mouse_left3.xpm");
	if (map->count >= 30)
		file_to_img(map, "Bonus/Xpms/mouse_left4.xpm");
	if (map->count >= 40)
		file_to_img(map, "Bonus/Xpms/mouse_left5.xpm");
	if (map->count >= 50)
		file_to_img(map, "Bonus/Xpms/mouse_left6.xpm");
	if (map->count >= 60)
		file_to_img(map, "Bonus/Xpms/mouse_left7.xpm");
	if (map->count >= 70)
		file_to_img(map, "Bonus/Xpms/mouse_left8.xpm");
	if (map->count >= 80)
		file_to_img(map, "Bonus/Xpms/mouse_left9.xpm");
}

int	mouse_update(t_map *map)
{
	map->count++;
	if (map->count <= 90)
	{
		if (map->direction == 'R')
			mouse_right_update(map);
		else
			mouse_left_update(map);
	}
	else
		map->count = 0;
	map_render(map, -1, -1);
	return (0);
}
