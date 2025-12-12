/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_ids.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:37:09 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 16:35:26 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_int.h"

static void	set_walls(t_game *game, int x, int y)
{
	char	up;
	char	down;
	t_tile	*tile;

	up = '2';
	if (y > 0)
		up = game->map.tiles[y - 1][x].value;
	down = '2';
	if (y < game->map.height - 1)
		down = game->map.tiles[y + 1][x].value;
	tile = &game->map.tiles[y][x];
	if (up != '1' && down == '1')
		tile->sprite_id = WALL_VERTICAL_TOP;
	else if ((up == '1' || up == '2') && down == '1')
		tile->sprite_id = WALL_VERTICAL;
	else if (up != '1')
		tile->sprite_id = WALL_HORIZONTAL_TOP;
	else
		tile->sprite_id = WALL_HORIZONTAL;
}

void	set_enemies_sprite_ids(t_game *game)
{
	int		i;
	t_enemy	*enemy;

	i = -1;
	while (++i < game->enemies_count)
	{
		enemy = &game->enemies[i];
		if (enemy->direction == UP)
			enemy->sprite_id = ENEMY_WALK_UP_0;
		else if (enemy->direction == LEFT)
			enemy->sprite_id = ENEMY_WALK_LEFT_0;
		else if (enemy->direction == RIGHT)
			enemy->sprite_id = ENEMY_WALK_RIGHT_0;
		else
			enemy->sprite_id = ENEMY_WALK_DOWN_0;
	}
}

void	set_sprite_ids(t_game *game)
{
	int		y;
	int		x;
	t_tile	*tile;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			tile = &game->map.tiles[y][x];
			if (tile->value == '0' || tile->value == 'E')
				tile->sprite_id = FLOOR;
			else if (tile->value == '1')
				set_walls(game, x, y);
			else if (tile->value == '2')
				tile->sprite_id = VOID;
			else if (tile->value == 'C')
				tile->sprite_id = CHEST_OPEN;
		}
	}
	game->player.sprite_id = PLAYER_WALK_DOWN_0;
}
