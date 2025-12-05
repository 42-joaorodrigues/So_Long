/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:00:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/05 15:42:03 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "lft_print.h"

void	init_enemies(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->enemies_count)
	{
		game->enemies[i].step = 0;
		game->enemies[i].last_move = 0;
	}
}

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

static int	should_bounce(t_game *game, int x, int y)
{
	char	tile;

	if (is_out_of_bounds(game, x, y))
		return (1);
	tile = game->map.tiles[y][x].value;
	if (tile == '2')
		return (1);
	return (0);
}

static void	move_enemy_horizontal(t_game *game, t_enemy *enemy)
{
	enemy->step = !enemy->step;
	if (enemy->direction == RIGHT)
	{
		if (should_bounce(game, enemy->x + 1, enemy->y))
			enemy->direction = LEFT;
		else
			enemy->x++;
		enemy->sprite_id = GHOST_RIGHT + enemy->step;
	}
	else
	{
		if (should_bounce(game, enemy->x - 1, enemy->y))
			enemy->direction = RIGHT;
		else
			enemy->x--;
		enemy->sprite_id = GHOST_LEFT + enemy->step;
	}
}

static void	move_enemy_vertical(t_game *game, t_enemy *enemy)
{
	enemy->step = !enemy->step;
	if (enemy->direction == DOWN)
	{
		if (should_bounce(game, enemy->x, enemy->y + 1))
			enemy->direction = UP;
		else
			enemy->y++;
		enemy->sprite_id = GHOST_DOWN + enemy->step;
	}
	else
	{
		if (should_bounce(game, enemy->x, enemy->y - 1))
			enemy->direction = DOWN;
		else
			enemy->y--;
		enemy->sprite_id = GHOST_UP + enemy->step;
	}
}

int	check_enemy_collision(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->enemies_count)
	{
		if (is_enemy_in_wall(game, &game->enemies[i]))
			continue ;
		if (game->enemies[i].x == game->player.x
			&& game->enemies[i].y == game->player.y)
			return (1);
	}
	return (0);
}

void	render_enemies(t_game *game)
{
	int	i;
	int	opacity;

	i = -1;
	while (++i < game->enemies_count)
	{
		if (is_enemy_in_wall(game, &game->enemies[i]))
			opacity = 50;
		else
			opacity = 80;
		render_enemy(game, game->enemies[i], opacity);
	}
}

void	update_enemies(t_game *game)
{
	int			i;
	static long	last_update = 0;
	long		current_time;

	current_time = get_time_ms();
	if (current_time - last_update < 300)
		return ;
	last_update = current_time;
	i = -1;
	while (++i < game->enemies_count)
	{
		render_element_at(game, game->enemies[i].x, game->enemies[i].y);
		if (game->enemies[i].type == HORIZONTAL)
			move_enemy_horizontal(game, &game->enemies[i]);
		else
			move_enemy_vertical(game, &game->enemies[i]);
	}
	render_enemies(game);
	render_player(game);
}
