/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:59:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/04 14:10:19 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64

#include <stdio.h> // degub

# include "error_codes.h"
# include "key_codes.h"
# include "sprites.h"

enum			e_direction
{
	UP,
	LEFT,
	RIGHT,
	DOWN
};

typedef struct s_tile
{
	char		value;
	int			sprite_id;
}				t_tile;

typedef struct s_map
{
	t_tile		**tiles;
	int			width;
	int			height;
	int			collectible_count;
	int			exit_x;
	int			exit_y;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			direction;
	long		last_move;
	int			collected;
}				t_player;

typedef struct s_enemy
{
	int			type;
	int			x;
	int			y;
	int			direction;
}				t_enemy;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_enemy		enemies[10];
	int			enemies_count;
	int			move_count;
	void		**sprites;
	void		*mlx;
	void		*win;
	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;
	int			key_up;
	int			key_left;
	int			key_down;
	int			key_right;
	long		last_input_time;
}				t_game;

// parser
void			parse_map(t_game *game, const char *filename);

// render
void			render_map(t_game *game);

// keyhooks
void			handle_keys(t_game *game);
// move
void			update_player(t_game *game, int direction);
void			render_player(t_game *game, int x, int y, int frame);

// enemy
void			update_enemies(t_game *game);
void			render_enemies(t_game *game);
int				check_enemy_collision(t_game *game);

// util
void			put_tile(t_game *game, void *sprite, int x, int y);
void			put_transparent_tile(t_game *game, void *bg, void *fg, int x, int y);
long			get_time_ms(void);
void			ft_msleep(long msec);

// exit
int				ft_print_error(int err_code);
void			ft_free_exit(t_game *game, int err_code);

#endif // SO_LONG_H
