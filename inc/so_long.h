/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:59:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/02 11:02:44 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64

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
	int			direction;
	long		last_move;
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

// util
void			put_tile(t_game *game, void *sprite, int x, int y);
long			get_time_ms(void);

// exit
int				ft_print_error(int err_code);
void			ft_free_exit(t_game *game, int err_code);

#endif // SO_LONG_H
