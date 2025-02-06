/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:23:38 by tmillot           #+#    #+#             */
/*   Updated: 2025/02/06 14:21:54 by tmillot          ###   ########.fr       */
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
	int	s;

	s = data.size_img;
	if (c == '1')
		data.img = handling_wall(data, x, y);
	else if (c == '0')
	{
		if ((7 * x - 3 * y + 2 * x * y) % 5 == 0)
			data.img = mlx_xpm_file_to_image(data.mlx, FLOOR2, &s, &s);
		else if ((3 * x + 2 * y + 7 * x * y) % 5 == 0 && (y % 2) == 0)
			data.img = mlx_xpm_file_to_image(data.mlx, FLOOR3, &s, &s);
		else
			data.img = mlx_xpm_file_to_image(data.mlx, FLOOR1, &s, &s);
	}
	else if (c == 'C')
		data.img = mlx_xpm_file_to_image(data.mlx, COLLECTIBLE, &s, &s);
	else if (data.nb_collectible_pick == data.nb_collectible)
		data.img = mlx_xpm_file_to_image(data.mlx, EXIT, &s, &s);
	else if (c == 'E' && data.nb_collectible_pick != data.nb_collectible)
		data.img = mlx_xpm_file_to_image(data.mlx, FLOOR1, &s, &s);
	if (c == 'P')
		data.img = mlx_xpm_file_to_image(data.mlx, PLAYER_D, &s, &s);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img,
		x * SIZE, y * SIZE);
	mlx_destroy_image(data.mlx, data.img);
}
