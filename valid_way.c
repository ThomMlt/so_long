/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:58:27 by thomas            #+#    #+#             */
/*   Updated: 2025/01/27 16:50:45 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char ***tab, t_data data, int x, int y)
{
	if (y < 0 || y >= data.height || x < 0 || x >= data.width
		|| ((*tab)[y][x] != '0' && (*tab)[y][x] != 'C' && (*tab)[y][x] != 'P'))
		return;
	(*tab)[y][x] = 'F';
	fill(tab, data, x - 1, y);
    fill(tab, data, x + 1, y);
    fill(tab, data, x, y - 1);
    fill(tab, data, x, y + 1);
}

int	check_valid_way(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'C')
				return (0);
			if (map[j][i] == 'E')
				if (!(map[j][i - 1] == 'F' || map[j][i + 1] == 'F'
				|| map[j + 1][i] == 'F'|| map[j - 1][i] == 'F'))
				{
					return (0);
				}
			i++;
		}
		j++;
	}
	return (1);
}

void	flood_fill(t_data data)
{
	char		**copy_map;

	copy_map = copy_tab(data.map);
	if (!copy_map)
		exit_error("Failed to copy map");
	fill(&copy_map, data, data.start_x, data.start_y);
	int i = 0;
	while (copy_map[i] != NULL)
	{
		printf("%s\n", copy_map[i]);
		i++;
	}
	if (check_valid_way(copy_map) == 0)
		exit_error("no way possible for finish");
	free_tab_char(copy_map);
}
