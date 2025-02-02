/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:23:38 by tmillot           #+#    #+#             */
/*   Updated: 2025/02/02 23:02:48 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_window_image_beggin(t_data data)
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

void	put_texture(t_data data, int x, int y, char c)
{
	if (c == '1')
		data.img = mlx_xpm_file_to_image(data.mlx, WALL, &data.size_img, &data.size_img);
	else if (c == '0')
	{
		if ((y % 2) == 0 && (x % 1) != 0)
			data.img = mlx_xpm_file_to_image(data.mlx, FLOOR2, &data.size_img, &data.size_img);
		else
			data.img = mlx_xpm_file_to_image(data.mlx, FLOOR1, &data.size_img, &data.size_img);
	}
	else if (c == 'C')
		data.img = mlx_xpm_file_to_image(data.mlx, COLLECTIBLE, &data.size_img, &data.size_img);
	else if (c == 'E' && data.nb_collectible_pick == data.nb_collectible)
		data.img = mlx_xpm_file_to_image(data.mlx, EXIT, &data.size_img, &data.size_img);
	else if (c == 'E' && data.nb_collectible_pick != data.nb_collectible)
		data.img = mlx_xpm_file_to_image(data.mlx, FLOOR1, &data.size_img, &data.size_img);
	if (c == 'P')
		data.img  = mlx_xpm_file_to_image(data.mlx, PLAYER_D, &data.size_img, &data.size_img);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, x * SIZE_IMG, y * SIZE_IMG);
	mlx_destroy_image(data.mlx, data.img);
}
