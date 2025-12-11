/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:01:15 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/11 16:26:09 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_print.h"
#include "mlx.h"
#include "so_long.h"

static void	move(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = game->player.x;
	old_y = game->player.y;
	if (game->player.was_in_chest)
	{
		game->map.tiles[old_y][old_x].value = 'O';
		game->map.tiles[old_y][old_x].sprite_id = CHEST1;
		game->player.was_in_chest = 0;
	}
	render_element_at(game, old_x, old_y);
	render_element_at(game, new_x, new_y);
	game->player.x = new_x;
	game->player.y = new_y;
	game->player.move_count++;
	render_counter(game);
	ft_printf("\r\033[KMoves: %d", game->player.move_count);
}

void	update_player(t_game *game, int x_offset, int y_offset, int direction)
{
	int		new_x;
	int		new_y;
	char	c;

	game->player.is_idle = 0;
	game->player.direction = direction;
	game->player.step = !game->player.step;
	new_x = game->player.x + x_offset;
	new_y = game->player.y + y_offset;
	c = game->map.tiles[new_y][new_x].value;
	if (c != '1')
		move(game, new_x, new_y);
	render_player(game);
	if (c == 'C')
	{
		game->player.collected_count++;
		game->player.was_in_chest = 1;
		if (game->player.collected_count == game->map.collectible_count)
			exit_tile_animation(game);
	}
	if (c == 'E' && game->player.collected_count == game->map.collectible_count)
	{
		ft_printf("\r\033[KMoves: %d\nCongratulations, you've won!\n",
			game->player.move_count);
		ft_free_exit(game, 0);
	}
}
