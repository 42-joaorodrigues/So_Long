/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:18:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/30 19:07:46 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

static void	load_sprites2(t_game *game, char *sprite_addr[])
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
		game->sprites[i] = mlx_xpm_file_to_image(game->mlx, sprite_addr[i],
				&width, &height);
		if (!game->sprites[i])
			ft_free_exit(game, E_SPRITES_MISSING);
	}
}

void	load_sprites(t_game *game)
{
	load_sprites2(game, (char *[]){"assets/player_up0.xpm",
		"assets/player_up1.xpm", "assets/player_up2.xpm",
		"assets/player_left0.xpm", "assets/player_left1.xpm",
		"assets/player_left2.xpm", "assets/player_right0.xpm",
		"assets/player_right1.xpm", "assets/player_right2.xpm",
		"assets/player_down0.xpm", "assets/player_down1.xpm",
		"assets/player_down2.xpm", "assets/player_chest.xpm",
		"assets/chest0.xpm", "assets/chest1.xpm",
		"assets/void.xpm",
		"assets/wall_v_top.xpm", "assets/wall_v.xpm",
		"assets/wall_h_top.xpm", "assets/wall_h.xpm",
		"assets/floor.xpm", "assets/map_exit.xpm"});
}
