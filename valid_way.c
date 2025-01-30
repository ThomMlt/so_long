/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:58:27 by thomas            #+#    #+#             */
/*   Updated: 2025/01/30 13:12:34 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_tab(char **tab)
{
	char	**cpy;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (tab[len] != NULL)
		len++;
	cpy = (char **)malloc(sizeof(char *) * (len + 1));
	if (!cpy)
		return (NULL);
	while (tab[i] != NULL)
	{
		cpy[i] = ft_strdup(tab[i]);
		if (!cpy[i])
			return (free_tab_char(&cpy[i]), NULL);
		i++;
	}
	cpy[len] = NULL;
	return (cpy);
}

void	fill(char ***tab, t_data data, int x, int y)
{
	if (y < 0 || y >= data.height || x < 0 || x >= data.width
		|| ((*tab)[y][x] != '0' && (*tab)[y][x] != 'C' && (*tab)[y][x] != 'P'
		&& (*tab)[y][x] != 'E'))
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
			if (map[j][i] == 'C' || map[j][i] == 'E')
				return (0);
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
	if (check_valid_way(copy_map) == 0)
		exit_error("no way possible for finish");
	free_tab_char(copy_map);
}
