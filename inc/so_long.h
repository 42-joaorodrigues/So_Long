/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:59:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 16:44:57 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "directions_util.h"
# include "error_codes.h"
# include "key_util.h"
# include "sprites.h"
# include <stdio.h> // degub

# define ENEMY_SPEED 300

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
	int			step;
	int			direction;
	int			sprite_id;
	int			move_count;
	int			collected_count;
	int			is_idle;
	int			was_in_chest;
}				t_player;

typedef struct s_enemy
{
	int			type;
	int			x;
	int			y;
	int			direction;
	int			sprite_id;
	int			speed;
	int			step;
	long		last_move;
}				t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_enemy		enemies[10];
	int			enemies_count;
	void		**sprites;
	t_keys		key_pressed;
	long		last_input_time;
	int			exit_animating;
	int			exit_frame;
	long		exit_anim_time;
	long		last_collision_time;
}				t_game;

/* Parser */
void			parse_map(t_game *game, const char *filename);

/* Render */
// sprites
void			load_sprites(t_game *game);
// render
void			render_element_at(t_game *game, int x, int y);
void			render_all(t_game *game);
// BONUS enemy
void			render_enemy(t_game *game, t_enemy enemy);
void			render_enemies(t_game *game);
// player
void			render_player(t_game *game);
// BONUS counter
void			render_counter(t_game *game);

/* Input */
void			handle_keys(t_game *game);
int				key_loop(t_game *game, long current_time);

/* Game */
// player
void			update_player(t_game *game, int x_offset, int y_offset,
					int direction);
// BONUS enemy
void			update_enemies(t_game *game);
int				check_enemy_collision(t_game *game);
// BONUS exit_animation
void			exit_tile_animation(t_game *game);
void			update_exit_animation(t_game *game);

/* UTIL */
// util
void			put_tile(t_game *game, void *sprite, int x, int y);
int				is_out_of_bounds(t_game *game, int x, int y);
long			get_time_ms(void);
// mlx_util
void			*create_blended_image(t_game *game, void *bg, void *fg);
// exit
int				ft_print_error(int err_code);
void			ft_free_exit(t_game *game, int err_code);

#endif // SO_LONG_H
