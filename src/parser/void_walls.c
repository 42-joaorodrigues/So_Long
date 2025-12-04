/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:31:39 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/04 18:48:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "render_int.h"
#include <stdlib.h>

static int	check_sides(t_game *game, int x, int y)
{
	int	up;
	int	left;
	int	right;
	int	down;

	up = '1';
	if (y > 0)
		up = game->map.tiles[y - 1][x].value;
	left = '1';
	if (x > 0)
		left = game->map.tiles[y][x - 1].value;
	right = '1';
	if (x < game->map.width - 1)
		left = game->map.tiles[y][x + 1].value;
	down = '1';
	if (y < game->map.height - 1)
		down = game->map.tiles[y + 1][x].value;
	return ((up == '1' || up == '2') && (down == '1' || down == '2')
		&& (left == '1' || left == '2') && (right == '1' || right == '2'));
}

static int	check_diagonals(t_game *game, int x, int y)
{
	int	up_left;
	int	up_right;
	int	down_left;
	int	down_right;

	up_left = '1';
	if (y > 0 && x > 0)
		up_left = game->map.tiles[y - 1][x - 1].value;
	up_right = '1';
	if (y > 0 && x < game->map.width - 1)
		up_right = game->map.tiles[y - 1][x + 1].value;
	down_left = '1';
	if (y < game->map.height - 1 && x > 0)
		up_right = game->map.tiles[y + 1][x - 1].value;
	down_right = '1';
	if (y < game->map.height - 1 && x < game->map.width - 1)
		down_right = game->map.tiles[y + 1][x + 1].value;
	return ((up_left == '1' || up_left == '2') && (down_right == '1'
			|| down_right == '2') && (up_right == '1' || up_right == '2')
		&& (down_left == '1' || down_left == '2'));
}

void	mark_void_walls(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.tiles[y][x].value == '1' && check_sides(game, x, y)
				&& check_diagonals(game, x, y))
				game->map.tiles[y][x].value = '2';
		}
	}
}
