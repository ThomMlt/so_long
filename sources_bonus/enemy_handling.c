/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:00:07 by tmillot           #+#    #+#             */
/*   Updated: 2025/02/07 16:45:30 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_enemy(t_data *data)
{
	int			i;
	int			j;

	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == 'M')
			{
				data->enemy_y = j;
				data->enemy_x = i;
				data->enemy_dir = 1;
				data->speed = 1;
			}
			i++;
		}
		j++;
	}
}

void	update_enemy_position(t_data *data)
{
	data->enemy_x = data->enemy_dir * data->speed;
	if (data->map[data->enemy_y][data->enemy_x + data->enemy_dir] == '1')
		data->enemy_dir = -1;
	if (data->enemy_x < 0)
		data->enemy_x = 1;
	if (data->enemy_x >= data->width)
		data->enemy_x = data->width - 1;
}

void	draw_enemy(t_data *data)
{
	data->enemy = mlx_xpm_file_to_image(data->mlx, ENNEMIE, &data->size_img, &data->size_img);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->enemy, data->enemy_x * data->size_img, data->enemy_y* data->size_img);
}

int     animation_loop(t_data *data)
{
    // Efface l'écran (ou redessine toute la carte si nécessaire)
    // mlx_clear_window(data->mlx, data->mlx_win);
    build_window_image_beggin(*data); // Redessine la carte (à adapter)
    update_enemy_position(data);
    draw_enemy(data);

    return (0);
}
