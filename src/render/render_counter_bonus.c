/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_counter_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:00:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 16:34:17 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_conversion.h"
#include "lft_string.h"
#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>

void	render_counter(t_game *game)
{
	int		counter_x;
	int		counter_y;
	char	*move_count_str;

	if (game->player.move_count > 999)
		return ;
	counter_x = (game->map.width - 3) * TILE_SIZE;
	counter_y = 0;
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[VOID],
		counter_x, counter_y);
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[VOID],
		counter_x + TILE_SIZE, counter_y);
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[VOID],
		counter_x + TILE_SIZE * 2, counter_y);
	move_count_str = ft_itoa(game->player.move_count);
	move_count_str = ft_strjoin_free("Moves: ", move_count_str, 2);
	mlx_string_put(game->mlx, game->win, counter_x + 30, counter_y + 40,
		0xFFDEEED6, move_count_str);
	free(move_count_str);
}
