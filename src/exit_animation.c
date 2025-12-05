/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:55:20 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/05 15:20:39 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	exit_tile_animation(t_game *game)
{
	int	i;

	mlx_do_sync(game->mlx);
	i = -1;
	while (++i < 4)
	{
		ft_msleep(500);
		put_tile(game, game->sprites[EXIT1 + i], game->map.exit_x,
			game->map.exit_y);
		mlx_do_sync(game->mlx);
	}
	game->map.tiles[game->map.exit_y][game->map.exit_x].sprite_id = EXIT_FINAL;
}
