/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:00:07 by tmillot           #+#    #+#             */
/*   Updated: 2025/02/08 13:51:48 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_moves(t_data *data)
{
	char	*move_str;
	char	*temp;

	move_str = ft_itoa(data->move);
	if (!move_str)
		exit_error("Failed to allocate memory for move_str");
	temp = ft_strjoin("Moves: ", move_str);
	if (!temp)
	{
		free(move_str);
		exit_error("Failed to allocate memory for temp");
	}
	mlx_string_put(data->mlx, data->mlx_win, 10, 20, 0xFFFFFF, temp);
	free(move_str);
	free(temp);
}
