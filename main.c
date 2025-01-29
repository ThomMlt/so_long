/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:54:11 by thomas            #+#    #+#             */
/*   Updated: 2025/01/29 16:17:48 by tmillot          ###   ########.fr       */
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
	data->mlx = mlx_init();
	data->size_img = 64;
	data->mlx_win = mlx_new_window(data->mlx, ((data->width + 1) * SIZE_IMG), ((data->height + 1) * SIZE_IMG + 1), "so_long");
}

void	put_texture(t_data data, int x, int y, char c)
{	
	if (c == '1')
		data.img = mlx_xpm_file_to_image(data.mlx, WALL, &data.size_img, &data.size_img);
	if (c == '0' || c == 'C' || c == 'E')
		data.img = mlx_xpm_file_to_image(data.mlx, FLOOR, &data.size_img, &data.size_img);
	if (c == 'P')
		data.img = mlx_xpm_file_to_image(data.mlx, PLAYER, &data.size_img, &data.size_img);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, x * SIZE_IMG, y * SIZE_IMG);
}

void moove_player(t_data *data, int x, int y)
{
	if (data->map[data->start_x + x][data->start_y + y] != '1')
	{
		data->map[data->start_x][data->start_y] = '0';
		data->map[data->start_x + x][data->start_y + y] = 'P';
		data->start_x += x;
		data->start_y += y;
		build_window_image(*data);
	}	
}

void	key_hook(int keycode, t_data *data)
{
	if (keycode == ECHAP)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		exit(0);
	}
	else if (keycode == 'w')
		moove_player(data, -1, 0);
	else if (keycode == 's')
		moove_player(data, 1, 0);
	else if (keycode == 'd')
		moove_player(data, 0, 1);
	else if (keycode == 'a')
		moove_player(data, 0, -1);
}

void	build_window_image(t_data data)
{
	int	i;
	int	j;

	j = 0;
	while (data.map[j] != NULL)
	{
		i = 0;
		while (data.map[j][i] != '\0')
		{
			put_texture(data, i, j, data.map[j][i]);
			i++;
		}
		j++;
	}
}

int main(int argc, char **argv)
{
	t_data data;
	(void)argc;
	init_data(&data, argv[1]);
	flood_fill(data);
	build_window_image(data);
	// int i = 0;
	// int j = 0;
	// while (data.map[j] != NULL)
	// {
	// 	i = 0;
	// 	while (data.map[j][i] != '\0')
	// 	{
	// 		put_texture(data, i, j, data.map[j][i]);
	// 		i++;
	// 	}
	// 	j++;
	// }
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	mlx_loop(data.mlx);
	// free_tab_char(data.map);
	// return (0);
}
