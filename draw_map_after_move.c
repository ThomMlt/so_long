/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_after_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:21:17 by tmillot           #+#    #+#             */
/*   Updated: 2025/02/03 13:33:07 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_window_image_after_move(t_data data, int direction)
{
	int	i;
	int	j;

	j = 0;
	if (data.map[data.exit_y][data.exit_x] == '0')
		data.map[data.exit_y][data.exit_x] = 'E';
	while (data.map[j] != NULL)
	{
		i = 0;
		while (data.map[j][i] != '\0')
		{
			put_texture_after_move(data, i, j, data.map[j][i], direction);
			i++;
		}
		j++;
	}
}

void	put_texture_after_move(t_data data, int x, int y, char c, int direction)
{
	if (c != 'P')
		put_texture(data, x, y, c);
	else if (c == 'P')
	{
		if (direction == 1)
			data.img  = mlx_xpm_file_to_image(data.mlx, PLAYER_U, &data.size_img, &data.size_img);
		if (direction == 2)
			data.img  = mlx_xpm_file_to_image(data.mlx, PLAYER_D, &data.size_img, &data.size_img);
		if (direction == 3)
			data.img  = mlx_xpm_file_to_image(data.mlx, PLAYER_L, &data.size_img, &data.size_img);
		if (direction == 4)
			data.img  = mlx_xpm_file_to_image(data.mlx, PLAYER_R, &data.size_img, &data.size_img);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, x * SIZE_IMG, y * SIZE_IMG);
	mlx_destroy_image(data.mlx, data.img);
	}
}
