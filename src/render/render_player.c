/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:00:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 16:34:17 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	render_player(t_game *game)
{
	void	*img;
	int		x;
	int		y;
	void	*bg;
	int		frame;

	x = game->player.x;
	y = game->player.y;
	if (game->map.tiles[y][x].value == 'C')
	{
		put_tile(game, game->sprites[PLAYER_OPEN_CHEST], x, y);
		return ;
	}
	bg = game->sprites[game->map.tiles[y][x].sprite_id];
	frame = 0;
	if (!game->player.is_idle)
		frame = 1 + game->player.step;
	game->player.sprite_id = game->player.direction * 3 + frame;
	img = create_blended_image(game, bg, game->sprites[game->player.sprite_id]);
	put_tile(game, img, x, y);
	mlx_destroy_image(game->mlx, img);
}
