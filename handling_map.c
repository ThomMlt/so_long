/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:36:41 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/23 12:05:53 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab_char(char **tab)
{
	int y;

	y = 0;
	while (tab[y] != NULL)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}

void	exit_error(char *str)
{
	perror(str);
	exit(1);
}

void	duplicate_handling(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'P'
			&& str[i] != 'C' && str[i] != 'E' && str[i] != '\n')
			exit_error("map is not valid");
		if (str[i] == 'E' || str[i] == 'P')
		{
			i++;
			while (str[i + j] != '\0')
			{
				if (str[i + j] == 'E' || str[i + j] == 'P')
					exit_error("pls entry only one exit or one start");
				j++;
			}
		}
		i++;
	}
	printf("aucune erreur");
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
	duplicate_handling(str);
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
