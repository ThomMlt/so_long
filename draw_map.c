/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:23:38 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/30 13:24:30 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	put_texture(t_data data, int x, int y, char c)
{	
	if (c == '1')
		data.img = mlx_xpm_file_to_image(data.mlx, WALL, &data.size_img, &data.size_img);
	if (c == '0' || c == 'C' || c == 'E')
		data.img = mlx_xpm_file_to_image(data.mlx, FLOOR, &data.size_img, &data.size_img);
	if (c == 'C')
		data.img = mlx_xpm_file_to_image(data.mlx, COLLECTIBLE, &data.size_img, &data.size_img);
	if (c == 'E')
		data.img = mlx_xpm_file_to_image(data.mlx, EXIT, &data.size_img, &data.size_img);
	if (c == 'P')
		data.img = mlx_xpm_file_to_image(data.mlx, PLAYER, &data.size_img, &data.size_img);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, x * SIZE_IMG, y * SIZE_IMG);
}
