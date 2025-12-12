/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:00:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 16:39:52 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "enemy_int_bonus.h"

static void	move_single_enemy(t_game *game, int i)
{
	render_element_at(game, game->enemies[i].x, game->enemies[i].y);
	if (game->enemies[i].type == HORIZONTAL)
		move_enemy_horizontal(game, &game->enemies[i]);
	else
		move_enemy_vertical(game, &game->enemies[i]);
}

void	update_enemies(t_game *game)
{
	int		i;
	long	current_time;
	int		moved;

	current_time = get_time_ms();
	moved = 0;
	i = -1;
	while (++i < game->enemies_count)
	{
		if (current_time - game->enemies[i].last_move
			< game->enemies[i].speed)
			continue ;
		game->enemies[i].last_move = current_time;
		move_single_enemy(game, i);
		moved = 1;
	}
	if (moved)
	{
		render_enemies(game);
		render_player(game);
	}
}
