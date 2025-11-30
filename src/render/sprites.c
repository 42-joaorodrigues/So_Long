/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:18:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/30 16:11:08 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include "graphic.h"
#include "mlx.h"
#include <stdlib.h>

static void	ft_load_sprites2(t_game *game, char *sprite_addr[])
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
		game->sprites[i] = mlx_xpm_file_to_image(game->mlx, sprite_addr[i],
				&width, &height);
}

static void	ft_load_sprites(t_game *game)
{
	int	i;

	ft_load_sprites2(game, (char *[]){"assets/player_up0.xpm",
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
	i = -1;
	while (++i < N_SPRITES)
		if (!game->sprites[i])
			ft_free_exit(game, E_SPRITES_MISSING);
}

static void	ft_mark_void_walls(t_game *game)
{
	int		y;
	int		x;
	char	up;
	char	down;
	char	left;
	char	right;
	char	up_left;
	char	up_right;
	char	down_left;
	char	down_right;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == '1')
			{
				up = (y > 0) ? game->map.map[y - 1][x] : '1';
				down = (y < game->map.height - 1) ? game->map.map[y + 1][x] : '1';
				left = (x > 0) ? game->map.map[y][x - 1] : '1';
				right = (x < game->map.width - 1) ? game->map.map[y][x + 1] : '1';
				up_left = (y > 0 && x > 0) ? game->map.map[y - 1][x - 1] : '1';
				up_right = (y > 0 && x < game->map.width - 1) ? game->map.map[y - 1][x + 1] : '1';
				down_left = (y < game->map.height - 1 && x > 0) ? game->map.map[y + 1][x - 1] : '1';
				down_right = (y < game->map.height - 1 && x < game->map.width - 1) ? game->map.map[y + 1][x + 1] : '1';
				if ((up == '1' || up == '2') && (down == '1' || down == '2') && (left == '1' || left == '2') && (right == '1' || right == '2')
					&& (up_left == '1' || up_left == '2') && (up_right == '1' || up_right == '2')
					&& (down_left == '1' || down_left == '2') && (down_right == '1' || down_right == '2'))
					game->map.map[y][x] = '2';
			}
			x++;
		}
		y++;
	}
}

static void	ft_put_image(t_game *game, void *image_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image_ptr, x * TILE_SIZE, y
		* TILE_SIZE);
}

void	ft_render_map(t_game *game)
{
	int	y;
	int	x;

	ft_load_sprites(game);
	game->n_sprites = N_SPRITES;
	ft_mark_void_walls(game);
	game->map.map[game->player.y][game->player.x] = '0'; 
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == '0')
				ft_put_image(game, game->sprites[FLOOR], x, y);
			else if (game->map.map[y][x] == '1')
			{
				char up    = (y > 0) ? game->map.map[y - 1][x] : '2';
				char down  = (y < game->map.height - 1) ? game->map.map[y + 1][x] : '2';

				// 4 → Vertical top
				if (up != '1' && down == '1')
					ft_put_image(game, game->sprites[WALL_V_TOP], x, y);

				// 3 → Vertical no top
				else if ((up == '1' || up == '2') && down == '1')
					ft_put_image(game, game->sprites[WALL_V], x, y);

				// 6 → Horizontal top
				else if (up != '1')
					ft_put_image(game, game->sprites[WALL_H_TOP], x, y);

				// 5 → Horizontal no top
				else
					ft_put_image(game, game->sprites[WALL_H], x, y);
			}
			else if (game->map.map[y][x] == '2')
				ft_put_image(game, game->sprites[VOID], x, y);
			else if (game->map.map[y][x] == 'P')
				ft_put_image(game, game->sprites[PLAYER_UP1], x, y);
			else if (game->map.map[y][x] == 'C')
				ft_put_image(game, game->sprites[CHEST0], x, y);
			else if (game->map.map[y][x] == 'E')
				ft_put_image(game, game->sprites[MAP_EXIT], x, y);
			if (game->player.x == x && game->player.y == y)
				ft_put_image(game, game->sprites[PLAYER_DOWN1], x, y);
			x++;
		}
		y++;
	}
}
