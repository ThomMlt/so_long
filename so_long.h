/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:02:19 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/27 17:03:50 by thomas           ###   ########.fr       */
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
	int		nb_collectible;
	int		width; // nombre de colonne
	int		height; // nombre de ligne
	int		start_x; // colonne augmente en allant vers la droite
	int		start_y; // ligne augmente en descendant
	int 	exit_x;
	int 	exit_y;
}	t_data;

/* hangling free */
void	free_tab_char(char **tab);

/* hangling output error*/
void	exit_error(char *str);

/* map input management */
char	**get_map_str(char *filename);
int 	check_wall_side(char **map);
int		check_wall_top_bottom(char **map);
int		duplicate_handling_map(char *str);
int		map_if_rectangular(char **map);

/* init struct data */
void	get_start_position(t_data *data);
void	get_exit_position(t_data *data);
void	init_data(t_data *data, char *name_map);
int		get_height_map(char **map);

/* check if a valid way */
void		flood_fill(t_data data);
void		fill(char ***tab, t_data data, int x, int y);
int			check_valid_way(char **map);
char		**copy_tab(char **tab);

#endif