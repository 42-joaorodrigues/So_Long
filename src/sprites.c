/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:18:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/05 15:31:52 by joao-alm         ###   ########.fr       */
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
	load_sprite_array(game, (char *[]){"assets/player/player_up0.xpm",
		"assets/player/player_up1.xpm", "assets/player/player_up2.xpm",
		"assets/player/player_left0.xpm", "assets/player/player_left1.xpm",
		"assets/player/player_left2.xpm", "assets/player/player_right0.xpm",
		"assets/player/player_right1.xpm", "assets/player/player_right2.xpm",
		"assets/player/player_down0.xpm", "assets/player/player_down1.xpm",
		"assets/player/player_down2.xpm", "assets/player/player_chest.xpm",
		"assets/chest0.xpm", "assets/chest1.xpm",
		"assets/wall/void.xpm",
		"assets/wall/wall_v_top.xpm", "assets/wall/wall_v.xpm",
		"assets/wall/wall_h_top.xpm", "assets/wall/wall_h.xpm",
		"assets/floor.xpm",
		"assets/exit/exit1.xpm", "assets/exit/exit2.xpm",
		"assets/exit/exit3.xpm", "assets/exit/exit_final.xpm",
		"assets/ghost/ghost_up.xpm", "assets/ghost/ghost_up1.xpm",
		"assets/ghost/ghost_left.xpm", "assets/ghost/ghost_left1.xpm",
		"assets/ghost/ghost_right.xpm", "assets/ghost/ghost_right1.xpm",
		"assets/ghost/ghost_down.xpm", "assets/ghost/ghost_down1.xpm"});
}
