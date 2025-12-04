/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:00:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/04 13:15:20 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "lft_print.h"

static int	get_enemy_sprite(t_enemy *enemy)
{
	if (enemy->direction == UP)
		return (GHOST_UP);
	else if (enemy->direction == LEFT)
		return (GHOST_LEFT);
	else if (enemy->direction == RIGHT)
		return (GHOST_RIGHT);
	return (GHOST_DOWN);
}

static int	is_enemy_visible(t_game *game, t_enemy *enemy)
{
	char	tile;

	if (enemy->x < 0 || enemy->x >= game->map.width)
		return (0);
	if (enemy->y < 0 || enemy->y >= game->map.height)
		return (0);
	tile = game->map.array[enemy->y][enemy->x];
	if (tile == '1' || tile == '2')
		return (0);
	return (1);
}

static void	render_tile_at(t_game *game, int x, int y)
{
	char	tile;

	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return ;
	tile = game->map.array[y][x];
	if (tile == 'C')
		put_tile(game, game->sprites[CHEST0], x, y);
	else if (tile == 'O')
		put_tile(game, game->sprites[CHEST1], x, y);
	else if (tile == '1' || tile == '2')
		return ;
	else
		put_tile(game, game->sprites[FLOOR], x, y);
	if (game->player.x == x && game->player.y == y)
		render_player(game, x, y, 1);
}

static void	move_enemy(t_game *game, t_enemy *enemy)
{
	int	old_x;
	int	old_y;

	old_x = enemy->x;
	old_y = enemy->y;
	printf("type: %d\n", enemy->type);
	if (enemy->type == 0)
	{
		if (enemy->direction == RIGHT)
		{
			enemy->x++;
			if (enemy->x >= game->map.width - 1)
				enemy->direction = LEFT;
		}
		else
		{
			enemy->x--;
			if (enemy->x <= 0)
				enemy->direction = RIGHT;
		}
	}
	else
	{
		if (enemy->direction == DOWN)
		{
			enemy->y++;
			if (enemy->y >= game->map.height - 1)
				enemy->direction = UP;
		}
		else
		{
			enemy->y--;
			if (enemy->y <= 0)
				enemy->direction = DOWN;
		}
	}
	render_tile_at(game, old_x, old_y);
}

int	check_enemy_collision(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->enemies_count)
	{
		if (!is_enemy_visible(game, &game->enemies[i]))
			continue ;
		if (game->enemies[i].x == game->player.x
			&& game->enemies[i].y == game->player.y)
			return (1);
	}
	return (0);
}

static void	*get_bg_sprite(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map.array[y][x];
	if (tile == 'C')
		return (game->sprites[CHEST0]);
	else if (tile == 'O')
		return (game->sprites[CHEST1]);
	else if (tile == 'E')
		return (game->sprites[FLOOR]);
	return (game->sprites[FLOOR]);
}

void	render_enemies(t_game *game)
{
	int		i;
	void	*bg;

	i = -1;
	while (++i < game->enemies_count)
	{
		// bg = get_bg_sprite(game, game->enemies[i].x, game->enemies[i].y);
		// 	put_transparent_tile(game, bg,
		// 		game->sprites[get_enemy_sprite(&game->enemies[i])],
		// 		game->enemies[i].x, game->enemies[i].y);
		if (is_enemy_visible(game, &game->enemies[i]))
		{
			bg = get_bg_sprite(game, game->enemies[i].x, game->enemies[i].y);
			put_transparent_tile(game, bg,
				game->sprites[get_enemy_sprite(&game->enemies[i])],
				game->enemies[i].x, game->enemies[i].y);
		}
	}
}

void	update_enemies(t_game *game)
{
	int			i;
	static long	last_update = 0;
	long		current_time;

	current_time = get_time_ms();
	if (current_time - last_update < 600)
		return ;
	last_update = current_time;
	i = -1;
	while (++i < game->enemies_count)
		move_enemy(game, &game->enemies[i]);
	render_enemies(game);
	if (check_enemy_collision(game))
	{
		ft_printf("\r\033[KMoves: %d\nYou died!\n", game->move_count);
		ft_free_exit(game, 0);
	}
}
