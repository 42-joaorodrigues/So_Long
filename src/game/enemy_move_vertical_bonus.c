/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_vertical_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:40:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 17:20:16 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy_int_bonus.h"

static void	move_down(t_game *game, t_enemy *enemy)
{
	if (should_bounce(game, enemy->x, enemy->y + 1))
	{
		enemy->direction = UP;
		if (!should_bounce(game, enemy->x, enemy->y - 1))
		{
			enemy->y--;
			enemy->step = !enemy->step;
		}
	}
	else
	{
		enemy->y++;
		enemy->step = !enemy->step;
	}
}

static void	move_up(t_game *game, t_enemy *enemy)
{
	if (should_bounce(game, enemy->x, enemy->y - 1))
	{
		enemy->direction = DOWN;
		if (!should_bounce(game, enemy->x, enemy->y + 1))
		{
			enemy->y++;
			enemy->step = !enemy->step;
		}
	}
	else
	{
		enemy->y--;
		enemy->step = !enemy->step;
	}
}

void	move_enemy_vertical(t_game *game, t_enemy *enemy)
{
	if (enemy->direction == DOWN)
		move_down(game, enemy);
	else
		move_up(game, enemy);
	if (enemy->direction == DOWN)
		enemy->sprite_id = ENEMY_WALK_DOWN_0 + enemy->step;
	else
		enemy->sprite_id = ENEMY_WALK_UP_1 + enemy->step;
}
