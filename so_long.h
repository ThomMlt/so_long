/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:02:19 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/20 16:14:10 by tmillot          ###   ########.fr       */
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

#endif