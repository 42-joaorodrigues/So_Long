/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_collision_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:40:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 17:20:09 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy_int_bonus.h"

int	should_bounce(t_game *game, int x, int y)
{
	char	tile;

	if (is_out_of_bounds(game, x, y))
		return (1);
	tile = game->map.tiles[y][x].value;
	if (tile == '1' || tile == '2')
		return (1);
	return (0);
}

int	check_enemy_collision(t_game *game)
{
	int		i;
	long	current_time;

	current_time = get_time_ms();
	if (current_time - game->last_collision_time < 3000)
		return (0);
	i = -1;
	while (++i < game->enemies_count)
	{
		if (game->enemies[i].x == game->player.x
			&& game->enemies[i].y == game->player.y)
		{
			game->last_collision_time = current_time;
			return (1);
		}
	}
	return (0);
}
