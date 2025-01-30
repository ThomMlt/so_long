/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:54:11 by thomas            #+#    #+#             */
/*   Updated: 2025/01/30 13:30:49 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data data;
	(void)argc;
	init_data(&data, argv[1]);
	flood_fill(data);
	build_window_image(data);
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	mlx_loop(data.mlx);
}
