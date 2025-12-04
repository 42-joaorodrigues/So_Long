/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:58:21 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/04 20:35:08 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INT_H
# define PARSER_INT_H

# include "so_long.h"

// flood_fill
typedef struct s_flood_fill
{
	int	collectibles;
	int	exit_found;
}		t_flood_fill;

// validate_characters
typedef struct s_counts
{
	int	players_count;
	int	exits_count;
}		t_counts;

// validate_map
void	get_map_data(t_game *game);

// flood_fill
void	flood_fill(t_game *game);

// void_walls
void	mark_void_walls(t_game *game);

// sprites_ids
void	set_sprite_ids(t_game *game);

#endif // MAP_H
