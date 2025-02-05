/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:54:11 by thomas            #+#    #+#             */
/*   Updated: 2025/02/05 14:16:27 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
	{
		// if (ft_parsing() == 0)
		// {
			init_data(&data, argv[1]);
			flood_fill(data);
			build_window_image_beggin(data);
			mlx_hook(data.mlx_win, 2, 1L<<0, &key_hook, &data);
			mlx_hook(data.mlx_win, 17, 0, &close_window, &data);
			mlx_loop(data.mlx);
		// }
		// else
		// 	ft_printf("map is not valid");
	}
	else 
		ft_printf("pls entry only ./so_long map_name");
}
