/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:53:58 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/05 00:34:35 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

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
	put_tile(game, img, x, y);
	mlx_destroy_image(game->mlx, img);
}

void	render_player(t_game *game)
{
	void	*img;
	int		x;
	int		y;
	void	*bg;
	int 	frame;

	x = game->player.x;
	y = game->player.y;
	if (game->map.tiles[y][x].value == 'C')
	{
		put_tile(game, game->sprites[PLAYER_CHEST], x, y);
		return ;
	}
	bg = game->sprites[game->map.tiles[y][x].sprite_id];
	frame = 0;
	if (!game->player.is_idle)
	{
		game->player.step = !game->player.step;
		frame = 1 + game->player.step;
	}
	game->player.sprite_id = game->player.direction * 3 + frame;
	img = create_blended_image(game, bg, game->sprites[game->player.sprite_id],
			50);
	put_tile(game, img, x, y);
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
	render_player(game);
}
