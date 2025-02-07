/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:36:41 by tmillot           #+#    #+#             */
/*   Updated: 2025/02/06 17:02:42 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	while (map[last][i])
	{
		if (map[last][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_wall_side(char **map)
{
	int	j;
	int	len;

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
		|| check_wall_side(map) == 0 || if_empty_line(str) == 0)
		return (0);
	return (1);
}

static char	*read_map(int fd_map)
{
	char	*line;
	char	*str;
	char	*temp;

	line = get_next_line(fd_map);
	if (line == NULL)
		exit_error("map is empty");
	str = ft_strdup(line);
	free(line);
	line = get_next_line(fd_map);
	while (line != NULL)
	{
		temp = ft_strjoin(str, line);
		free(str);
		free(line);
		str = temp;
		line = get_next_line(fd_map);
	}
	return (str);
}

char	**get_map_str(char *filename)
{
	int		fd_map;
	char	*str;
	char	**map;

	fd_map = open(filename, O_RDONLY);
	if (fd_map == -1)
		exit_error("map don't exist");
	str = read_map(fd_map);
	map = ft_split(str, '\n');
	if (if_map_not_valid(str, map) == 0)
		exit_error_free("map not valid", str, map);
	free(str);
	return (close(fd_map), map);
}

/* 
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
			break ;
		str = ft_strjoin(str, line);
	}
	map = ft_split(str, '\n');
	if (if_map_not_valid(str, map) == 0)
		exit_error_free("map not valid", str, map);
	(free(str), free(line));
	return (close(fd_map), map);
}
*/
