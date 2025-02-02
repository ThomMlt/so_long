/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_draw_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:04:22 by thomas            #+#    #+#             */
/*   Updated: 2025/02/02 23:24:16 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*handling_wall(t_data data, int x, int y)
{
	t_img	*wall;
	
	if (y == 0 && x == 0)
		wall = mlx_xpm_file_to_image(data.mlx, WALL_C_R, &data.size_img, &data.size_img);
	else if (y == 0 && x < data.width)
		wall = mlx_xpm_file_to_image(data.mlx, WALL_U, &data.size_img, &data.size_img);
	else if (y == 0 && x == data.width)
		wall = mlx_xpm_file_to_image(data.mlx, WALL_C_L, &data.size_img, &data.size_img);
	else if (x == 0 && (y > 0 && y < data.height))
		wall = mlx_xpm_file_to_image(data.mlx, WALL_S_L, &data.size_img, &data.size_img);
	else if (x == data.width && (y > 0 && y < data.height))
		wall = mlx_xpm_file_to_image(data.mlx, WALL_S_R, &data.size_img, &data.size_img);
	else if (y == data.height && x == 0)
		wall = mlx_xpm_file_to_image(data.mlx, WALL_C_L_D, &data.size_img, &data.size_img);
	else if (y == data.height && (x < data.width))
		wall = mlx_xpm_file_to_image(data.mlx, WALL_D, &data.size_img, &data.size_img);
	else if (y == data.height && x == data.width)
		wall = mlx_xpm_file_to_image(data.mlx, WALL_C_R_D, &data.size_img, &data.size_img);
	return (wall);
}
