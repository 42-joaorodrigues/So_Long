/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:53:58 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 12:49:43 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "lft_conversion.h"
#include "lft_string.h"
#include <stdlib.h>

void	render_element_at(t_game *game, int x, int y)
{
	put_tile(game, game->sprites[game->map.tiles[y][x].sprite_id], x, y);
}

void	render_enemy(t_game *game, t_enemy enemy, int opacity)
{
	void	*img;
	int		x;
	int		y;
	void	*bg;

	x = enemy.x;
	y = enemy.y;
	bg = game->sprites[game->map.tiles[y][x].sprite_id];
	img = create_blended_image(game, bg, game->sprites[enemy.sprite_id], opacity);
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
		frame = 1 + game->player.step;
	game->player.sprite_id = game->player.direction * 3 + frame;
	img = create_blended_image(game, bg, game->sprites[game->player.sprite_id],
			100);
	put_tile(game, img, x, y);
	mlx_destroy_image(game->mlx, img);
}

void	render_counter(t_game *game)
{
	int		counter_x;
	int		counter_y;
	char	*move_count_str;

	if (game->player.move_count > 999)
		return ;
	counter_x = (game->map.width - 3) * TILE_SIZE;
	counter_y = 0;
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[VOID], counter_x, counter_y);
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[VOID], counter_x + TILE_SIZE, counter_y);
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[VOID], counter_x + TILE_SIZE * 2, counter_y);
	move_count_str = ft_itoa(game->player.move_count);
	move_count_str = ft_strjoin_free("Moves: ", move_count_str, 2);
	mlx_string_put(game->mlx, game->win, counter_x + 30, counter_y + 40, 0xFFDEEED6, move_count_str);
	free(move_count_str);
}

void	render_all(t_game *game)
{
	int	y;
	int	x;
	int	i;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
			render_element_at(game, x, y);
	}
	render_player(game);
	i = -1;
	while (++i < game->map.width)
		mlx_put_image_to_window(game->mlx, game->win, game->sprites[VOID], i * TILE_SIZE, 0);
	mlx_set_font(game->mlx, game->win, "-*-*-bold-r-*-*-20-*-*-*-*-*-*-*");
	render_counter(game);
}
