/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:54:11 by thomas            #+#    #+#             */
/*   Updated: 2025/01/27 17:13:29 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height_map(char **map)
{
	int	i;
	
	i = 0;
	while (map[i] != NULL)
		i++;
	return (i - 1);
}

void	init_data(t_data *data, char *name_map)
{
	data->map = get_map_str(name_map);
	data->width = (ft_strlen(data->map[0]) - 1);
	data->height = get_height_map(data->map);
	get_start_position(data);
	get_exit_position(data);
	data->nb_collectible = 0;
	// printf("position exit : y = %d x = %d\n", data->exit_y, data->exit_x);
	// printf("position p : y = %d x = %d\n", data->start_y, data->start_x);
	// printf("largeur %d\n", data->width);
	// printf("hauteur %d\n", data->height);
}

int main(int argc, char **argv)
{
	t_data data;
	(void)argc;
	init_data(&data, argv[1]);
	flood_fill(data);
	free_tab_char(data.map);
}