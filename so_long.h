/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:02:19 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/30 13:30:10 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft_complet/libft/libft.h"
# include "./libft_complet/gnl/get_next_line.h"
# include "./libft_complet/printf/ft_printf.h"
# include "./minilibx/mlx.h"
# include "./minilibx/mlx_int.h"

# define SIZE_IMG 64
# define PLAYER "./texture/player.xpm"
# define FLOOR "./texture/floor.xpm"
# define WALL "./texture/wall.xpm"
# define COLLECTIBLE "./texture/collectible.xpm"
# define EXIT "./texture/exit.xpm"
# define ECHAP 65307


typedef struct s_data
{
	char 		**map;
	int			nb_collectible;
	int			nb_collectible_pick;
	int			width; // nombre de colonne
	int			height; // nombre de ligne
	int			start_x; // colonne augmente en allant vers la droite
	int			start_y; // ligne augmente en descendant
	int			size_img;
	int 		exit_x;
	int 		exit_y;
	t_xvar		*mlx; // pour initialiser la minilibx
	t_win_list	*mlx_win; // pointer sur la fenetre
	t_img		*img; // pointer sur image
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
int		if_map_not_valid(char *str, char **map);

/* init struct data */
void	get_start_position(t_data *data);
void	get_exit_position(t_data *data);
void	init_data(t_data *data, char *name_map);
int		get_height_map(char **map);
int		count_collectible(char **map);

/* check if a valid way */
void		flood_fill(t_data data);
void		fill(char ***tab, t_data data, int x, int y);
int			check_valid_way(char **map);
char		**copy_tab(char **tab);

/* draw map */
void	build_window_image(t_data data);
void	put_texture(t_data data, int x, int y, char c);

/* move player */
void	move_player(t_data *data, int x, int y);
void	key_hook(int keycode, t_data *data);

#endif