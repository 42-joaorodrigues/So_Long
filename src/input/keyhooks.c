/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:14:44 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 15:51:54 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_print.h"
#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <stdlib.h>

int	key_press(const int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("\r\033[KMoves: %d\n", game->player.move_count);
		ft_free_exit(game, 0);
	}
	if (keycode == KEY_W)
		game->key_pressed.w = 1;
	else if (keycode == KEY_A)
		game->key_pressed.a = 1;
	else if (keycode == KEY_S)
		game->key_pressed.s = 1;
	else if (keycode == KEY_D)
		game->key_pressed.d = 1;
	else if (keycode == KEY_UP)
		game->key_pressed.up = 1;
	else if (keycode == KEY_LEFT)
		game->key_pressed.left = 1;
	else if (keycode == KEY_DOWN)
		game->key_pressed.down = 1;
	else if (keycode == KEY_RIGHT)
		game->key_pressed.right = 1;
	return (0);
}

int	key_release(const int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key_pressed.w = 0;
	else if (keycode == KEY_A)
		game->key_pressed.a = 0;
	else if (keycode == KEY_S)
		game->key_pressed.s = 0;
	else if (keycode == KEY_D)
		game->key_pressed.d = 0;
	else if (keycode == KEY_UP)
		game->key_pressed.up = 0;
	else if (keycode == KEY_LEFT)
		game->key_pressed.left = 0;
	else if (keycode == KEY_DOWN)
		game->key_pressed.down = 0;
	else if (keycode == KEY_RIGHT)
		game->key_pressed.right = 0;
	return (0);
}

int	key_loop(t_game *game, long current_time)
{
	if (game->key_pressed.w || game->key_pressed.up)
	{
		game->last_input_time = current_time;
		update_player(game, 0, -1, UP);
	}
	else if (game->key_pressed.a || game->key_pressed.left)
	{
		game->last_input_time = current_time;
		update_player(game, -1, 0, LEFT);
	}
	else if (game->key_pressed.d || game->key_pressed.right)
	{
		game->last_input_time = current_time;
		update_player(game, 1, 0, RIGHT);
	}
	else if (game->key_pressed.s || game->key_pressed.down)
	{
		game->last_input_time = current_time;
		update_player(game, 0, 1, DOWN);
	}
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
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_hook(game->win, ClientMessage, LeaveWindowMask, x_keyhook, game);
}
