/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:55:50 by thomas            #+#    #+#             */
/*   Updated: 2025/01/27 17:03:33 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_start_position(t_data *data)
{
	int			i;
	int			j;

	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == 'P')
			{
				data->start_y = j;
				data->start_x = i;
			}
			i++;
		}
		j++;
	}
}

void	get_exit_position(t_data *data)
{
	int			i;
	int			j;

	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == 'E')
			{
				data->exit_y = j;
				data->exit_x = i;
			}
			i++;
		}
		j++;
	}
}

char	**copy_tab(char **tab)
{
	char	**cpy;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (tab[len] != NULL)
		len++;
	cpy = (char **)malloc(sizeof(char *) * (len + 1));
	if (!cpy)
		return (NULL);
	while (tab[i] != NULL)
	{
		cpy[i] = ft_strdup(tab[i]);
		if (!cpy[i])
			return (free_tab_char(&cpy[i]), NULL);
		i++;
	}
	cpy[len] = NULL;
	return (cpy);
}
