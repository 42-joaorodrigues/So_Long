/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:18:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 14:46:09 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

static void	load_sprite_array(t_game *game, char *sprite_array[])
{
	int	width;
	int	height;
	int	i;

	game->sprites = malloc(sizeof(void *) * N_SPRITES);
	if (!game->sprites)
		ft_free_exit(game, E_MEMORY_ALLOC);
	width = TILE_SIZE;
	height = TILE_SIZE;
	i = -1;
	while (++i < N_SPRITES)
	{
		game->sprites[i] = mlx_xpm_file_to_image(game->mlx, sprite_array[i],
				&width, &height);
		if (!game->sprites[i])
			ft_free_exit(game, E_SPRITES_MISSING);
	}
}

void	load_sprites(t_game *game)
{
	load_sprite_array(game, (char *[]){"assets/player/idle_up.xpm",
		"assets/player/walk_up_0.xpm", "assets/player/walk_up_1.xpm",
		"assets/player/idle_left.xpm", "assets/player/walk_left_0.xpm",
		"assets/player/walk_left_1.xpm", "assets/player/idle_right.xpm",
		"assets/player/walk_right_0.xpm", "assets/player/walk_right_1.xpm",
		"assets/player/idle_down.xpm", "assets/player/walk_down_0.xpm",
		"assets/player/walk_down_1.xpm", "assets/player/open_chest.xpm",
		"assets/wall/vertical_top.xpm", "assets/wall/vertical.xpm",
		"assets/wall/horizontal_top.xpm", "assets/wall/horizontal.xpm",
		"assets/chest_close.xpm", "assets/chest_open.xpm",
		"assets/floor.xpm", "assets/void.xpm",
		"assets/exit/open_0.xpm", "assets/exit/open_1.xpm",
		"assets/bat/walk_up_0.xpm", "assets/bat/walk_up_1.xpm",
		"assets/spider/walk_left_0.xpm", "assets/spider/walk_left_1.xpm",
		"assets/spider/walk_right_0.xpm", "assets/spider/walk_right_1.xpm",
		"assets/bat/walk_down_0.xpm", "assets/bat/walk_down_1.xpm"});
}
