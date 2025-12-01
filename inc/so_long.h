/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:59:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/30 19:06:40 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64

# include "sprites.h"
# include "key_codes.h"

typedef struct s_map
{
	char		**array;
	int			width;
	int			height;
	int			exit_x;
	int			exit_y;
	int			collectible_count;
	int			n_players;
	int			n_exits;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			sprite;
	int			glasses;
}				t_player;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			direction;
	int			speed;
	int			active;
}				t_enemy;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	int			move_count;
	void		**sprites;
	int			n_sprites;
	void		*mlx;
	void		*win;
	int         player_direction; // 0=up, 1=left, 2=right, 3=down
	int         step;
}				t_game;

// parser
void			parse_map(t_game *game, const char *filename);

void			ft_window(t_game *game);

#endif // GAME_H
