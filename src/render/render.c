/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:53:58 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/30 19:04:30 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_int.h"

static void	ft_put_image(t_game *game, void *image_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image_ptr, x * TILE_SIZE, y
		* TILE_SIZE);
}

void	ft_render_walls(t_game *game, int x, int y)
{
	char	up;
	char	down;

	up = (y > 0) ? game->map.array[y - 1][x] : '2';
	down = (y < game->map.height - 1) ? game->map.array[y + 1][x] : '2';
	if (up != '1' && down == '1')
		ft_put_image(game, game->sprites[WALL_V_TOP], x, y);
	else if ((up == '1' || up == '2') && down == '1')
		ft_put_image(game, game->sprites[WALL_V], x, y);
	else if (up != '1')
		ft_put_image(game, game->sprites[WALL_H_TOP], x, y);
	else
		ft_put_image(game, game->sprites[WALL_H], x, y);
}

void	ft_render_map(t_game *game)
{
	int	y;
	int	x;

	load_sprites(game);
	ft_mark_void_walls(game);
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.array[y][x] == '0')
				ft_put_image(game, game->sprites[FLOOR], x, y);
			else if (game->map.array[y][x] == '1')
				ft_render_walls(game, x, y);
			else if (game->map.array[y][x] == '2')
				ft_put_image(game, game->sprites[VOID], x, y);
			else if (game->map.array[y][x] == 'C')
				ft_put_image(game, game->sprites[CHEST0], x, y);
			else if (game->map.array[y][x] == 'E')
				ft_put_image(game, game->sprites[MAP_EXIT], x, y);
			if (game->player.x == x && game->player.y == y)
				ft_put_image(game, game->sprites[PLAYER_DOWN1], x, y);
		}
	}
}
