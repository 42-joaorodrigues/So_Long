/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:55:20 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/11 16:39:00 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	exit_tile_animation(t_game *game)
{
	game->exit_animating = 1;
	game->exit_frame = 0;
	game->exit_anim_time = get_time_ms();
}

void	update_exit_animation(t_game *game)
{
	long	current_time;

	if (!game->exit_animating)
		return ;
	current_time = get_time_ms();
	if (current_time - game->exit_anim_time < 350)
		return ;
	game->exit_anim_time = current_time;
	game->map.tiles[game->map.exit_y][game->map.exit_x].sprite_id = EXIT2 + game->exit_frame;
	render_element_at(game, game->map.exit_x, game->map.exit_y);
	game->exit_frame++;
	if (game->exit_frame >= 2)
	{
		game->exit_animating = 0;
		game->map.tiles[game->map.exit_y][game->map.exit_x].sprite_id
			= EXIT_FINAL;
	}
}
