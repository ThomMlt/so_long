/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:01:54 by thomas            #+#    #+#             */
/*   Updated: 2025/02/06 14:23:01 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab_char(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}

void	exit_error(char *str)
{
	perror(str);
	exit(1);
}

void	exit_error_free(char *str, char *str_free, char **map)
{
	free(str_free);
	free_tab_char(map);
	perror(str);
	exit(1);
}

int	close_window(t_data *data)
{
	cleanup(data);
	exit(0);
	return (0);
}
