/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:36:41 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/27 16:18:31 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	duplicate_handling_map(char *str)
{
	int	i;
	int	count_E;
	int	count_C;
	int count_P;

	i = 0;
	count_C = 0;
	count_E = 0;
	count_P = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'P'
			&& str[i] != 'C' && str[i] != 'E' && str[i] != '\n')
			return(0);
		if (str[i] == 'E')
			count_E++;
		if (str[i] == 'C')
			count_C++;
		if (str[i] == 'P')
			count_P++;
		i++;
	}
	if (count_C < 1 || count_E != 1 || count_P != 1)
		return (0);
	return (1);
}

int	map_if_rectangular(char **map)
{
	int	i;
	int	len;
	int	len_next;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		len_next = ft_strlen(map[i]);
		if (len_next != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall_top_bottom(char **map)
{
	int	i;
	int	last;

	last = 0;
	i = 0;
	while (map[last] != NULL)
		last++;
	last--;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[last][i++])
	{
		if (map[last][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int check_wall_side(char **map)
{
    int j;
    int len;
    
    j = 1;
    if (check_wall_top_bottom(map) == 0)
        return (0);
    while (map[j] != NULL)
    {
        len = ft_strlen(map[j]);
        if (map[j][0] != '1')
            return (0);
        if (map[j][len - 1] != '1')
            return (0);
        j++;
    }
    return (1);
}

int	if_map_not_valid(char *str, char **map)
{
	if (duplicate_handling_map(str) == 0 || map_if_rectangular(map) == 0
		|| check_wall_side(map) == 0)
	{
		free(str);
		return (perror("map not valide"), 0);
	}
	return (1);
}

char	**get_map_str(char *filename)
{
	int		fd_map;
	char	*line;
	char	*str;
	char	**map;
	
	fd_map = open(filename, O_RDONLY);
	if (fd_map == -1)
		exit_error("map don't exist");
	line = get_next_line(fd_map);
	if (line == NULL)
		exit_error("map is empty");
	str = ft_strdup(line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd_map);
		if (line == NULL)
			break;
		str = ft_strjoin(str, line);
	}
	map = ft_split(str, '\n');
	if (if_map_not_valid(str, map) == 0)
		exit(0);
	(free(str), free(line));
	return (close(fd_map), map);
}

