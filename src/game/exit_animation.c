/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:55:20 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 15:23:44 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_tile_animation(t_game *game)
{
	game->exit_animating = 1;
	game->exit_anim_time = get_time_ms();
	game->map.tiles[game->map.exit_y][game->map.exit_x].sprite_id = EXIT_OPEN_0;
	render_element_at(game, game->map.exit_x, game->map.exit_y);
}

void	update_exit_animation(t_game *game)
{
	long	current_time;

	if (!game->exit_animating)
		return ;
	current_time = get_time_ms();
	if (current_time - game->exit_anim_time < 350)
		return ;
	game->map.tiles[game->map.exit_y][game->map.exit_x].sprite_id = EXIT_OPEN_1;
	render_element_at(game, game->map.exit_x, game->map.exit_y);
	game->exit_animating = 0;
}
