/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:36:41 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/23 22:46:50 by thomas           ###   ########.fr       */
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

int	map_if_rectangular(t_data data)
{
	int	i;
	int	len;
	int	len_next;

	i = 0;
	len = ft_strlen(data.map[0]);
	while (data.map[i] != NULL)
	{
		len_next = ft_strlen(data.map[i]);
		if (len_next != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall_top_bottom(t_data data)
{
	int	i;
	int	last;

	last = 0;
	i = 0;
	while (data.map[last] != NULL)
		last++;
	last--;
	while (data.map[0][i])
	{
		if (data.map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (data.map[last][i++])
	{
		if (data.map[last][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int check_wall_side(t_data data)
{
    int j;
    int len;
    
    j = 1;
    if (check_wall_top_bottom(data) == 0)
        return (0);
    while (data.map[j] != NULL)
    {
        len = ft_strlen(data.map[j]);
        if (data.map[j][0] != '1')
            return (0);
        if (data.map[j][len - 1] != '1')
            return (0);
        j++;
    }
    return (1);
}


void	get_map_str(t_data *data, char *filename)
{
	int		fd_map;
	char	*line;
	char	*str;
	
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
	data->map = ft_split(str, '\n');
	free(line);
	if (duplicate_handling_map(str) == 0 || map_if_rectangular(*data) == 0 || check_wall_side(*data) == 0)
		return (free(str), close(fd_map), exit_error("map not valide"));
	free(str);
	close(fd_map);
}

int main(int argc, char **argv)
{
	t_data *data;
	(void)argc;
	data = malloc(sizeof(t_data));
	get_map_str(data, argv[1]);
	free_tab_char(data->map);
	free(data);
}
