/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:01:15 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/04 23:01:05 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_print.h"
#include "mlx.h"
#include "so_long.h"

void	init_player(t_game *game)
{
	game->player.step = 0;
	game->player.move_count = 0;
	game->player.last_move_ms = 0;
	game->player.collected_count = 0;
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

void	animate_player_walk(t_game *game)
{
	game->player.step = !game->player.step;
	render_player(game, game->player.step + 1);
}

static void	move(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = game->player.x;
	old_y = game->player.y;
	render_element_at(game, old_x, old_y);
	render_element_at(game, new_x, new_y);
	game->player.x = new_x;
	game->player.y = new_y;
	game->player.move_count++;
	animate_player_walk(game);
	ft_printf("\r\033[KMoves: %d", game->player.move_count);
}

void	update_player(t_game *game, int direction)
{
	int		new_x;
	int		new_y;
	char	*c;

	game->player.last_move_ms = get_time_ms();
	game->player.direction = direction;
	get_new_pos(game, direction, &new_x, &new_y);
	c = &game->map.tiles[new_y][new_x].value;
	if (is_out_of_bounds(game, new_x, new_y) || *c == '1')
	{
		animate_player_walk(game);
		return ;
	}
	if (*c == 'C')
	{
		game->player.collected_count++;
		*c = 'O';
		game->map.tiles[new_y][new_x].sprite_id = CHEST1;
		move(game, new_x, new_y);
		if (game->player.collected_count == game->map.collectible_count)
		{
			exit_tile_animation(game);
			game->map.tiles[game->map.exit_y][game->map.exit_x].value = 'E';
		}
		return ;
	}
	move(game, new_x, new_y);
	if (*c == 'E' && game->player.collected_count == game->map.collectible_count)
	{
		ft_printf("\r\033[KMoves: %d\nCongratulations, you've won!\n",
			game->player.move_count);
		ft_free_exit(game, 0);
	}
}
