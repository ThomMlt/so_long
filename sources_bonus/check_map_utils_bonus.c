/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:09:56 by tmillot           #+#    #+#             */
/*   Updated: 2025/02/07 16:16:29 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	if_empty_line(char *str)
{
	int	i;
	int	line_start;

	i = 0;
	line_start = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (line_start)
				return (0);
			line_start = 1;
		}
		else if (str[i] != ' ' && str[i] != '\t')
		{
			line_start = 0;
		}
		i++;
	}
	return (1);
}

int	duplicate_handling_map(char *str)
{
	int	i;
	int	c_e;
	int	c_c;
	int	c_p;

	i = 0;
	c_c = 0;
	c_e = 0;
	c_p = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'P'
			&& str[i] != 'C' && str[i] != 'E' && str[i] != '\n' && str[i] != 'M')
			return (0);
		if (str[i] == 'E')
			c_e++;
		if (str[i] == 'C')
			c_c++;
		if (str[i] == 'P')
			c_p++;
		i++;
	}
	if (c_c < 1 || (c_e > 1 || c_e == 0) || (c_p > 1 || c_p == 0))
		return (0);
	return (1);
}

int	map_if_rectangular(char **map)
{
	int	i;
	int	len;
	int	len_next;

	i = 0;
	len = ft_strlen(map[0]) - 1;
	while (map[i] != NULL)
	{
		len_next = ft_strlen(map[i]) - 1;
		if (len_next != len)
			return (0);
		i++;
	}
	return (1);
}

char	**get_map_parse(t_data data, char *filename)
{
	char	**map;

	map = get_map_str(filename);
	flood_fill(data);
	return (map);
}
