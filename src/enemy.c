/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:00:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/11 14:44:24 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "lft_print.h"

static int	is_enemy_in_wall(t_game *game, t_enemy *enemy)
{
	char	tile;

	if (is_out_of_bounds(game, enemy->x, enemy->y))
		return (1);
	tile = game->map.tiles[enemy->y][enemy->x].value;
	if (tile == '1')
		return (1);
	return (0);
}

// static int	is_enemy_at(t_game *game, int x, int y, t_enemy *self)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < game->enemies_count)
// 	{
// 		if (&game->enemies[i] == self)
// 			continue ;
// 		if (game->enemies[i].x == x && game->enemies[i].y == y)
// 			return (1);
// 	}
// 	return (0);
// }

static int	should_bounce(t_game *game, int x, int y, t_enemy *enemy)
{
	char	tile;

	if (is_out_of_bounds(game, x, y))
		return (1);
	tile = game->map.tiles[y][x].value;
	if (tile == '1' || tile == '2')
		return (1);
	(void)enemy;
	// if (is_enemy_at(game, x, y, enemy))
	// 	return (1);
	return (0);
}

static void	move_enemy_horizontal(t_game *game, t_enemy *enemy)
{
	if (enemy->direction == RIGHT)
	{
		if (should_bounce(game, enemy->x + 1, enemy->y, enemy))
		{
			enemy->direction = LEFT;
			enemy->x--;
		}
		else
		{
			enemy->x++;
			enemy->step = !enemy->step;
		}
	}
	else
	{
		if (should_bounce(game, enemy->x - 1, enemy->y, enemy))
		{
			enemy->direction = RIGHT;
			enemy->x++;
		}
		else
		{
			enemy->x--;
			enemy->step = !enemy->step;
		}
	}
	if (enemy->direction == RIGHT)
		enemy->sprite_id = GHOST_RIGHT + enemy->step;
	else
		enemy->sprite_id = GHOST_LEFT + enemy->step;
}

static void	move_enemy_vertical(t_game *game, t_enemy *enemy)
{
	if (enemy->direction == DOWN)
	{
		if (should_bounce(game, enemy->x, enemy->y + 1, enemy))
		{
			enemy->direction = UP;
			enemy->y--;
		}
		else
		{
			enemy->y++;
			enemy->step = !enemy->step;
		}
	}
	else
	{
		if (should_bounce(game, enemy->x, enemy->y - 1, enemy))
		{
			enemy->direction = DOWN;
			enemy->y++;
		}
		else
		{
			enemy->y--;
			enemy->step = !enemy->step;
		}
	}
	if (enemy->direction == DOWN)
		enemy->sprite_id = GHOST_DOWN + enemy->step;
	else
		enemy->sprite_id = GHOST_UP + enemy->step;
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
		if (is_enemy_in_wall(game, &game->enemies[i]))
			continue ;
		if (game->enemies[i].x == game->player.x
			&& game->enemies[i].y == game->player.y)
		{
			game->last_collision_time = current_time;
			return (1);
		}
	}
	return (0);
}

void	render_enemies(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->enemies_count)
		render_enemy(game, game->enemies[i], 80);
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
		render_element_at(game, game->enemies[i].x, game->enemies[i].y);
		if (game->enemies[i].type == HORIZONTAL)
			move_enemy_horizontal(game, &game->enemies[i]);
		else
			move_enemy_vertical(game, &game->enemies[i]);
		moved = 1;
	}
	if (moved)
	{
		render_enemies(game);
		render_player(game);
	}
}
