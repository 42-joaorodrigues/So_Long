/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:01:15 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/03 13:30:36 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "lft_print.h"

void	render_player(t_game *game, int x, int y, int frame)
{
	int			sprite_id;

	if (game->map.array[y][x] == 'O')
	{
		put_tile(game, game->sprites[PLAYER_CHEST], x, y);
		return ;
	}
	if (game->player.direction == UP)
		sprite_id = PLAYER_UP0;
	else if (game->player.direction == LEFT)
		sprite_id = PLAYER_LEFT0;
	else if (game->player.direction == RIGHT)
		sprite_id = PLAYER_RIGHT0;
	else
		sprite_id = PLAYER_DOWN0;
	put_tile(game, game->sprites[sprite_id + frame], x, y);
}

static void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map.array[y][x];
	if (tile == 'C')
		put_tile(game, game->sprites[CHEST0], x, y);
	else if (tile == 'O')
		put_tile(game, game->sprites[CHEST1], x, y);
	else
		put_tile(game, game->sprites[FLOOR], x, y);
}

static void	get_new_pos(t_game *game, int direction, int *new_x, int *new_y)
{
	*new_x = game->player.x;
	*new_y = game->player.y;
	if (direction == UP)
		(*new_y)--;
	else if (direction == LEFT)
		(*new_x)--;
	else if (direction == RIGHT)
		(*new_x)++;
	else if (direction == DOWN)
		(*new_y)++;
}

static void	move(t_game *game, int new_x, int new_y)
{
	int			old_x;
	int			old_y;
	static int	step = 0;

	old_x = game->player.x;
	old_y = game->player.y;
	step = !step;
	game->player.x = new_x;
	game->player.y = new_y;
	game->move_count++;
	render_tile(game, old_x, old_y);
	render_tile(game, new_x, new_y);
	render_player(game, new_x, new_y, step ? 2 : 0);
	ft_printf("\r\033[KMoves: %d", game->move_count);
}

static void	exit_tile_animation(t_game *game)
{
	ft_msleep(500);
	put_tile(game, game->sprites[EXIT1], game->map.exit_x, game->map.exit_y);
	ft_msleep(500);
	put_tile(game, game->sprites[EXIT2], game->map.exit_x, game->map.exit_y);
	ft_msleep(500);
	put_tile(game, game->sprites[EXIT3], game->map.exit_x, game->map.exit_y);
	ft_msleep(500);
	put_tile(game, game->sprites[EXIT4], game->map.exit_x, game->map.exit_y);
}

static void	animate_walk_in_place(t_game *game)
{
	static int	step = 0;

	if (!step)
		step = 2;
	else
		step = 0;
	render_player(game, game->player.x, game->player.y, step);
}

void	update_player(t_game *game, int direction)
{
	int	new_x;
	int	new_y;

	game->player.direction = direction;
	game->player.last_move = get_time_ms();
	get_new_pos(game, direction, &new_x, &new_y);
	if (new_x < 0 || new_x >= game->map.width || new_y < 0
		|| new_y >= game->map.height)
	{
		animate_walk_in_place(game);
		return ;
	}
	if (game->map.array[new_y][new_x] == '1')
	{
		animate_walk_in_place(game);
		return ;
	}
	if (game->map.array[new_y][new_x] == 'E'
		&& game->map.collectible_count > 0)
	{
		animate_walk_in_place(game);
		return ;
	}
	if (game->map.array[new_y][new_x] == 'C')
	{
		game->map.array[new_y][new_x] = 'O';
		game->map.collectible_count--;
		if (game->map.collectible_count <= 0)
		{
			move(game, new_x, new_y);
			exit_tile_animation(game);
			return ;
		}
	}
	move(game, new_x, new_y);
	if (game->map.array[new_y][new_x] == 'E'
		&& game->map.collectible_count == 0)
	{
		ft_printf("Moves: %d\nCongratulations, you've won!\n", game->move_count);
		ft_free_exit(game, 0);
	}
}
