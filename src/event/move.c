/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:01:15 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/30 19:04:45 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include "event.h"
#include "mlx.h"
#include "lft_print.h"

/*
** Get the correct sprite index based on direction and step
*/
static int	get_player_sprite(int direction, int step)
{
	int	frame;

	// Alternate between frame 0 and frame 2
	frame = (step == 0) ? 0 : 2;
	
	if (direction == 0)  // Up
		return (PLAYER_UP0 + frame);
	else if (direction == 1)  // Left
		return (PLAYER_LEFT0 + frame);
	else if (direction == 2)  // Right
		return (PLAYER_RIGHT0 + frame);
	else  // Down
		return (PLAYER_DOWN0 + frame);
}

/*
** Render a tile at position (considers what's on map + player)
*/
static void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	// Always render floor first
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[FLOOR],
		x * TILE_SIZE, y * TILE_SIZE);
	
	tile = game->map.array[y][x];
	
	// Render map content
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites[CHEST0],
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'O')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites[CHEST1],
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites[MAP_EXIT],
			x * TILE_SIZE, y * TILE_SIZE);
	
	// Render player on top if at this position
	if (game->player.x == x && game->player.y == y)
	{
		if (tile == 'C' || tile == 'O')
			mlx_put_image_to_window(game->mlx, game->win,
				game->sprites[PLAYER_CHEST], x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->sprites[get_player_sprite(game->player_direction, game->step)],
				x * TILE_SIZE, y * TILE_SIZE);
	}
}

static void	ft_move(t_game *game, const t_point *new_pos,
	const t_point *old_pos, int direction)
{
	// Update direction and step
	game->player_direction = direction;
	game->step = !game->step;
	
	// Update player position
	game->player.x = new_pos->x;
	game->player.y = new_pos->y;
	game->move_count++;
	
	// Redraw old tile (without player)
	render_tile(game, old_pos->x, old_pos->y);
	
	// Redraw new tile (with player)
	render_tile(game, new_pos->x, new_pos->y);
	
	ft_printf("Moves: %d\r", game->move_count);
}

void	ft_update_player_pos(t_game *game, int x_offset, int y_offset)
{
	t_point	new_pos;
	int		direction;

	new_pos.x = game->player.x + x_offset;
	new_pos.y = game->player.y + y_offset;
	
	// Determine direction
	if (y_offset < 0)
		direction = 0;  // Up
	else if (x_offset < 0)
		direction = 1;  // Left
	else if (x_offset > 0)
		direction = 2;  // Right
	else
		direction = 3;  // Down
	
	if (new_pos.x < 0 || new_pos.x >= game->map.width || new_pos.y < 0
		|| new_pos.y >= game->map.height)
		return ;
	
	// Check what's at new position
	if (game->map.array[new_pos.y][new_pos.x] == '1')
		return ;  // Wall
	
	if (game->map.array[new_pos.y][new_pos.x] == 'E'
		&& game->map.collectible_count > 0)
		return ;  // Exit but not all collected
	
	// Collect chest if present
	if (game->map.array[new_pos.y][new_pos.x] == 'C')
	{
		game->map.array[new_pos.y][new_pos.x] = 'O';  // Mark as opened
		game->map.collectible_count--;
	}
	
	// Move player
	ft_move(game, &new_pos, &(t_point){game->player.x, game->player.y}, direction);
	
	// Check win condition
	if (game->map.array[new_pos.y][new_pos.x] == 'E'
		&& game->map.collectible_count == 0)
	{
		ft_printf("Moves: %d\nCongratulations, you've won!\n", game->move_count);
		ft_free_exit(game, E_OK);
	}
}
