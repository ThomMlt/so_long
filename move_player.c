/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:24:46 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/30 13:29:16 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_data *data, int x, int y)
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
		move_player(data, -1, 0);
	else if (keycode == 's')
		move_player(data, 1, 0);
	else if (keycode == 'd')
		move_player(data, 0, 1);
	else if (keycode == 'a')
		move_player(data, 0, -1);
}
