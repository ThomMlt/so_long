/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:02:19 by tmillot           #+#    #+#             */
/*   Updated: 2025/02/07 16:05:47 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft_complet/libft/libft.h"
# include "../libft_complet/gnl/get_next_line.h"
# include "../libft_complet/printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

# define SIZE 64
# define PLAYER_D "../texture/player_down.xpm"
# define PLAYER_U "../texture/player_up.xpm"
# define PLAYER_L "../texture/player_left.xpm"
# define PLAYER_R "../texture/player_right.xpm"
# define FLOOR1 "../texture/floor_1.xpm"
# define FLOOR2 "../texture/floor_2.xpm"
# define FLOOR3 "../texture/floor_3.xpm"
# define WALL_D "../texture/wall_down.xpm"
# define WALL_U "../texture/wall_up.xpm"
# define WALL_S_L "../texture/side_left.xpm"
# define WALL_S_R "../texture/side_right.xpm"
# define WALL_C_L "../texture/corner_up_left.xpm"
# define WALL_C_R "../texture/corner_up_right.xpm"
# define WALL_C_L_D "../texture/corner_down_left.xpm"
# define WALL_C_R_D "../texture/corner_down_right.xpm"
# define ROCK "../texture/wall_middle.xpm"
# define ROCK2 "../texture/wall_2.xpm"
# define HOLE "../texture/hole.xpm"
# define COLLECTIBLE "../texture/collectible.xpm"
# define EXIT "../texture/exit.xpm"
# define ENNEMIE "../texture/ennemies.xpm"
# define ECHAP 65307

typedef struct s_data
{
	char		**map;
	int			nb_collectible;
	int			nb_collectible_pick;
	int			width;
	int			height;
	int			start_x;
	int			start_y;
	int			size_img;
	int			exit_x;
	int			exit_y;
	int			enemy_x;
	int			enemy_y;
	int			enemy_dir;
	int			speed;
	int			move;
	t_xvar		*mlx;
	t_win_list	*mlx_win;
	t_img		*img;
	t_img		*enemy;
}	t_data;

/* hangling free */
void	free_tab_char(char **tab);
void	exit_error_free(char *str, char *str_free, char **map);
void	cleanup(t_data *data);

/* hangling output error*/
void	exit_error(char *str);
int		close_window(t_data *data);

/* map input management */
char	**get_map_str(char *filename);
int		check_wall_side(char **map);
int		check_wall_top_bottom(char **map);
int		duplicate_handling_map(char *str);
int		map_if_rectangular(char **map);
int		if_map_not_valid(char *str, char **map);
int		if_empty_line(char *str);
int		check_extension(char *name_map);

/* init struct data */
void	get_start_position(t_data *data);
void	get_exit_position(t_data *data);
void	init_data(t_data *data, char *name_map);
int		get_height_map(char **map);
int		count_collectible(char **map);

/* check if a valid way */
int		flood_fill(t_data data);
void	fill(char ***tab, t_data data, int x, int y);
int		check_valid_way(char **map);
char	**copy_tab(char **tab);
char	**get_map_parse(t_data data, char *filename);

/* draw map in beggin*/
void	build_window_image_beggin(t_data data);
void	put_texture(t_data data, int x, int y, char c);
t_img	*handling_wall(t_data data, int x, int y);
void	build_window_image_after_move(t_data data, int direction);
void	put_texture_after_move(t_data data, int x, int y, int direction);

/* move player */
void	move_player_up(t_data *data);
void	move_player_down(t_data *data);
void	move_player_left(t_data *data);
void	move_player_right(t_data *data);
int		key_hook(int keycode, t_data *data);

/* handling enemy */
void	find_enemy(t_data *data);
void	update_enemy_position(t_data *data);
void	draw_enemy(t_data *data);
int     animation_loop(t_data *data);

#endif