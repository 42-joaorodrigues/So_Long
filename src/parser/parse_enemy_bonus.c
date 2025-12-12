/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:48:34 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 16:35:39 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_int.h"

void	parse_enemy(t_game *game, int x, int y, char *c)
{
	if (game->enemies_count >= 10)
		ft_free_exit(game, E_MANY_ENEMIES);
	game->enemies[game->enemies_count].type = (*c == 'V' || *c == 'v');
	game->enemies[game->enemies_count].x = x;
	game->enemies[game->enemies_count].y = y;
	if (*c == 'H')
	{
		game->enemies[game->enemies_count].direction = RIGHT;
		if (x > game->map.width / 2)
			game->enemies[game->enemies_count].direction = LEFT;
	}
	else
	{
		game->enemies[game->enemies_count].direction = DOWN;
		if (y > game->map.height / 2)
			game->enemies[game->enemies_count].direction = UP;
	}
	game->enemies[game->enemies_count].speed = ENEMY_SPEED;
	if (*c == 'h' || *c == 'v')
		game->enemies[game->enemies_count].speed = ENEMY_SPEED / 2;
	game->enemies_count++;
	*c = '0';
}
