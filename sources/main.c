/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:54:11 by thomas            #+#    #+#             */
/*   Updated: 2025/02/06 14:28:42 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup(t_data *data)
{
	if (data->map)
		free_tab_char(data->map);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		init_data(&data, argv[1]);
		if (flood_fill(data) == 0)
		{
			cleanup(&data);
			exit(0);
		}
		build_window_image_beggin(data);
		mlx_hook(data.mlx_win, 2, 1L << 0, &key_hook, &data);
		mlx_hook(data.mlx_win, 17, 0, &close_window, &data);
		mlx_loop(data.mlx);
	}
	else
		ft_printf("pls entry only ./so_long map_name");
}
