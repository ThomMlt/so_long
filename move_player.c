/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:24:46 by tmillot           #+#    #+#             */
/*   Updated: 2025/02/05 14:14:05 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_map(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	exit(0);
}

void	move_player_up(t_data *data)
{
	if (data->map[data->start_y - 1][data->start_x] != '1')
	{
		if (data->map[data->start_y - 1][data->start_x] == 'C')
			data->nb_collectible_pick += 1;
		// if (data->start_x != data->exit_x || (data->start_y - 1) != data->exit_y)
		data->map[data->start_y][data->start_x] = '0';
		if (data->start_y - 1 == data->exit_y && data->start_x == data->exit_x && data->nb_collectible_pick == data->nb_collectible)
			end_map(data);
		data->map[data->start_y - 1][data->start_x] = 'P';
		data->start_y -= 1;
		data->move += 1;
		ft_printf("move player : %d\n", data->move);
		// build_window_image_after_move(*data, 1);
	}
	build_window_image_after_move(*data, 1);
}

void	move_player_down(t_data *data)
{
	if (data->map[data->start_y + 1][data->start_x] != '1')
	{
		if (data->map[data->start_y + 1][data->start_x] == 'C')
			data->nb_collectible_pick += 1;
		// if (data->start_x != data->exit_x || (data->start_y + 1) != data->exit_y)
		data->map[data->start_y][data->start_x] = '0';
		if (data->start_y + 1 == data->exit_y && data->start_x == data->exit_x && data->nb_collectible_pick == data->nb_collectible)
			end_map(data);
		data->map[data->start_y + 1][data->start_x] = 'P';
		data->start_y += 1;
		data->move += 1;
		ft_printf("move player : %d\n", data->move);
		// build_window_image_after_move(*data, 2);
	}
	build_window_image_after_move(*data, 2);
}

void	move_player_left(t_data *data)
{
	if (data->map[data->start_y][data->start_x - 1] != '1')
	{
		if (data->map[data->start_y][data->start_x - 1] == 'C')
			data->nb_collectible_pick += 1;
		// if ((data->start_x - 1) != data->exit_x || data->start_y != data->exit_y)
		data->map[data->start_y][data->start_x] = '0';
		if (data->start_y == data->exit_y && data->start_x - 1 == data->exit_x && data->nb_collectible_pick == data->nb_collectible)
			end_map(data);
		data->map[data->start_y][data->start_x - 1] = 'P';
		data->start_x -= 1;
		data->move += 1;
		ft_printf("move player : %d\n", data->move);
		// build_window_image_after_move(*data, 3);
	}
	build_window_image_after_move(*data, 3);
}

void	move_player_right(t_data *data)
{
	if (data->map[data->start_y][data->start_x + 1] != '1')
	{
		if (data->map[data->start_y][data->start_x + 1] == 'C')
			data->nb_collectible_pick += 1;
		// if ((data->start_x + 1)  != data->exit_x || data->start_y != data->exit_y)
		data->map[data->start_y][data->start_x] = '0';
		if (data->start_y == data->exit_y && data->start_x + 1 == data->exit_x && data->nb_collectible_pick == data->nb_collectible)
			end_map(data);
		data->map[data->start_y][data->start_x + 1] = 'P';
		data->start_x += 1;
		data->move += 1;
		ft_printf("move player : %d\n", data->move);
		// build_window_image_after_move(*data, 4);
	}
	build_window_image_after_move(*data, 4);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ECHAP)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		exit(0);
	}
	else if (keycode == 'w')
		move_player_up(data);
	else if (keycode == 's')
		move_player_down(data);
	else if (keycode == 'd')
		move_player_right(data);
	else if (keycode == 'a')
		move_player_left(data);
	return (1);
}
