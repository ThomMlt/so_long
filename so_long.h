/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:02:19 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/23 22:21:32 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft_complet/libft/libft.h"
# include "./libft_complet/gnl/get_next_line.h"
# include "./libft_complet/printf/ft_printf.h"

typedef struct s_data
{
	char 	**map;
	int 	x;
	int 	y;
}	t_data;

/* hangling free */
void	free_tab_char(char **tab);

/* hangling output error*/
void	exit_error(char *str);

/* map input management */
void	get_map_str(t_data *data, char *filename);
int	duplicate_handling_map(char *str);

#endif