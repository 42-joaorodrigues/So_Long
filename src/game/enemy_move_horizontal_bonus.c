/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_horizontal_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:40:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 17:20:20 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy_int_bonus.h"

static void	move_right(t_game *game, t_enemy *enemy)
{
	if (should_bounce(game, enemy->x + 1, enemy->y))
	{
		enemy->direction = LEFT;
		if (!should_bounce(game, enemy->x - 1, enemy->y))
		{
			enemy->x--;
			enemy->step = !enemy->step;
		}
	}
	else
	{
		enemy->x++;
		enemy->step = !enemy->step;
	}
}

static void	move_left(t_game *game, t_enemy *enemy)
{
	if (should_bounce(game, enemy->x - 1, enemy->y))
	{
		enemy->direction = RIGHT;
		if (!should_bounce(game, enemy->x + 1, enemy->y))
		{
			enemy->x++;
			enemy->step = !enemy->step;
		}
	}
	else
	{
		enemy->x--;
		enemy->step = !enemy->step;
	}
}

void	move_enemy_horizontal(t_game *game, t_enemy *enemy)
{
	if (enemy->direction == RIGHT)
		move_right(game, enemy);
	else
		move_left(game, enemy);
	if (enemy->direction == RIGHT)
		enemy->sprite_id = ENEMY_WALK_RIGHT_0 + enemy->step;
	else
		enemy->sprite_id = ENEMY_WALK_LEFT_0 + enemy->step;
}
