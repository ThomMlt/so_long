/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_draw_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:04:22 by thomas            #+#    #+#             */
/*   Updated: 2025/02/06 14:25:03 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*handling_wall_mid(t_data data, int x, int y)
{
	t_img	*wall;
	int		s;

	wall = NULL;
	s = data.size_img;
	if (data.map[y - 1][x] != '1' && data.map[y + 1][x] != '1' &&
		data.map[y][x - 1] != '1' && data.map[y][x + 1] != '1')
		wall = mlx_xpm_file_to_image(data.mlx, HOLE, &s, &s);
	else if ((y % 2) == 0)
		wall = mlx_xpm_file_to_image(data.mlx, ROCK, &s, &s);
	else if ((y % 2) != 0)
		wall = mlx_xpm_file_to_image(data.mlx, ROCK2, &s, &s);
	return (wall);
}

t_img	*handling_wall(t_data data, int x, int y)
{
	t_img	*wall;
	int		s;

	wall = NULL;
	s = data.size_img;
	if (y == 0 && x == 0)
		wall = mlx_xpm_file_to_image(data.mlx, WALL_C_L, &s, &s);
	else if (y == 0 && x < data.width)
		wall = mlx_xpm_file_to_image(data.mlx, WALL_U, &s, &s);
	else if (y == 0 && x == data.width)
		wall = mlx_xpm_file_to_image(data.mlx, WALL_C_R, &s, &s);
	else if (x == 0 && (y > 0 && y < data.height))
		wall = mlx_xpm_file_to_image(data.mlx, WALL_S_L, &s, &s);
	else if (x == data.width && (y > 0 && y < data.height))
		wall = mlx_xpm_file_to_image(data.mlx, WALL_S_R, &s, &s);
	else if (y == data.height && x == 0)
		wall = mlx_xpm_file_to_image(data.mlx, WALL_C_L_D, &s, &s);
	else if (y == data.height && (x < data.width))
		wall = mlx_xpm_file_to_image(data.mlx, WALL_D, &s, &s);
	else if (y == data.height && x == data.width)
		wall = mlx_xpm_file_to_image(data.mlx, WALL_C_R_D, &s, &s);
	else
		wall = handling_wall_mid(data, x, y);
	return (wall);
}
