/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjarhbou <yjarhbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:50:38 by yjarhbou          #+#    #+#             */
/*   Updated: 2022/06/21 21:29:17 by yjarhbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_with(t_map *map)
{
	int	len;
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map->field[++i])
	{
		j = -1;
		len = 0;
		while (map->field[i][++j] != '\n' && map->field[i][j])
			len++;
		if (len != map->width)
		{
			printf("Error\nInconsistent map!\n");
			free (map->field);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_walls(t_map *map)
{
	int	x;

	x = -1;
	while (++x < map->width)
	{
		if (map->field[0][x] != '1' || map->field[map->height - 1][x] != '1')
		{
			printf("Error\nThe walls are not placed properly!\n");
			free (map->field);
			exit(EXIT_FAILURE);
		}
	}
	x = -1;
	while (++x < map->height)
	{
		if (map->field[x][0] != '1' || map->field[x][map->width - 1] != '1')
		{
			printf("Error\nThe walls are not placed properly!\n");
			free (map->field);
			exit(EXIT_FAILURE);
		}
	}
}

void	helper(t_map *map, int i, int j)
{
	if (map->field[i][j] != '0'
		&& map->field[i][j] != 'P'
		&& map->field[i][j] != '1'
		&& map->field[i][j] != 'C'
		&& map->field[i][j] != 'E')
	{
		printf("Error\nInvalid character in the map!\n");
		free (map->field);
		exit(EXIT_FAILURE);
	}
	if (map->field[i][j] == 'P')
	{
		map->player++;
		map->p_x = i;
		map->p_y = j;
	}
	else if (map->field[i][j] == 'E')
		map->exit++;
	else if (map->field[i][j] == 'C')
		map->collect++;
}

void	check_content(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			helper(map, i, j);
	}
	if (map->player != 1 || map->exit == 0 || map->collect == 0)
	{
		if (map->player != 1)
			printf("Error\nNumber of players is inconvenient!\n");
		if (map->exit == 0)
			printf("Error\nThe exit is missing!\n");
		if (map->collect == 0)
			printf("Error\nNo collectables in the map!\n");
		free (map->field);
		exit(EXIT_FAILURE);
	}
}

void	valid_map(t_map *map, int fd, char *av)
{
	int	i;

	i = 0;
	while (get_next_line(fd))
		map->height++;
	if (map->height == 0)
		ft_perror("invalid map", 1);
	if (close(fd) == -1)
		ft_perror("Error while closing the file", 1);
	map->field = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->field)
		exit(EXIT_FAILURE);
	fd = open (av, O_RDONLY);
	while (i < map->height)
		map->field[i++] = get_next_line(fd);
	close (fd);
	i = 0;
	while (map->field[0][i] != '\n')
		i++;
	map->width = i;
	map->field[map->height] = 0;
	check_with(map);
	check_walls(map);
	check_content(map);
}
