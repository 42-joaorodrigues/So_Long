/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:14:44 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/15 16:03:41 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_print.h"
#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <stdlib.h>

int	key_press(const int keycode, t_game *game)
{
	game->last_input_time = get_time_ms();
	if (keycode == KEY_ESC)
	{
		ft_printf("\r\033[KMoves: %d\n", game->player.move_count);
		ft_free_exit(game, 0);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		update_player(game, 0, -1, UP);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		update_player(game, -1, 0, LEFT);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		update_player(game, 0, 1, DOWN);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		update_player(game, 1, 0, RIGHT);
	return (0);
}

int	x_keyhook(t_game *game)
{
	ft_printf("\r\033[KMoves: %d\n", game->player.move_count);
	ft_free_exit(game, 0);
	return (0);
}

void	handle_keys(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, ClientMessage, LeaveWindowMask, x_keyhook, game);
}
