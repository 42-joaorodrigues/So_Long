/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:00:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 16:34:17 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	render_enemy(t_game *game, t_enemy enemy)
{
	void	*img;
	int		x;
	int		y;
	void	*bg;

	x = enemy.x;
	y = enemy.y;
	bg = game->sprites[game->map.tiles[y][x].sprite_id];
	img = create_blended_image(game, bg, game->sprites[enemy.sprite_id]);
	put_tile(game, img, x, y);
	mlx_destroy_image(game->mlx, img);
}

void	render_enemies(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->enemies_count)
		render_enemy(game, game->enemies[i]);
}
