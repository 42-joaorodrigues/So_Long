/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:53:58 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/04 20:58:03 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite, x * TILE_SIZE, y
		* TILE_SIZE);
}

void	render_element_at(t_game *game, int x, int y)
{
	put_tile(game, game->sprites[game->map.tiles[y][x].sprite_id], x, y);
}

void	render_enemy(t_game *game, t_enemy enemy)
{
	void	*img;
	int		x;
	int		y;
	void	*bg;

	x = enemy.x;
	y = enemy.y;
	bg = game->sprites[game->map.tiles[y][x].sprite_id];
	img = create_blended_image(game, bg, game->sprites[enemy.sprite_id], 50);
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE,
		y * TILE_SIZE);
	mlx_destroy_image(game->mlx, img);
}

void	render_player(t_game *game)
{
	void	*img;
	int		x;
	int		y;
	void	*bg;

	x = game->player.x;
	y = game->player.y;
	bg = game->sprites[game->map.tiles[y][x].sprite_id];
	img = create_blended_image(game, bg, game->sprites[game->player.sprite_id], 100);
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE,
		y * TILE_SIZE);
	mlx_destroy_image(game->mlx, img);
}

void	render_all(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
			render_element_at(game, x, y);
	}
}
