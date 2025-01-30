/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:09:05 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/30 13:11:38 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data, char *name_map)
{
	data->map = get_map_str(name_map);
	data->width = (ft_strlen(data->map[0]) - 1);
	data->height = get_height_map(data->map);
	get_start_position(data);
	get_exit_position(data);
	data->nb_collectible = count_collectible(data->map);
	data->mlx = mlx_init();
	data->size_img = 64;
	data->mlx_win = mlx_new_window(data->mlx, ((data->width + 1) * SIZE_IMG), ((data->height + 1) * SIZE_IMG + 1), "so_long");
}

int	get_height_map(char **map)
{
	int	i;
	
	i = 0;
	while (map[i] != NULL)
		i++;
	return (i - 1);
}

int	count_collectible(char **map)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'C')
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

void	get_start_position(t_data *data)
{
	int			i;
	int			j;

	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == 'P')
			{
				data->start_y = j;
				data->start_x = i;
			}
			i++;
		}
		j++;
	}
}

void	get_exit_position(t_data *data)
{
	int			i;
	int			j;

	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == 'E')
			{
				data->exit_y = j;
				data->exit_x = i;
			}
			i++;
		}
		j++;
	}
}
