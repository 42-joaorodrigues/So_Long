/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:14:44 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/03 17:04:23 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "lft_print.h"
#include "mlx.h"
#include <X11/X.h>
#include <stdlib.h>

int	key_press(const int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("\r\033[KMoves: %d\n", game->move_count);
		ft_free_exit(game, 0);
	}
	if (keycode == KEY_W)
		game->key_w = 1;
	else if (keycode == KEY_A)
		game->key_a = 1;
	else if (keycode == KEY_S)
		game->key_s = 1;
	else if (keycode == KEY_D)
		game->key_d = 1;
	else if (keycode == KEY_UP)
		game->key_up = 1;
	else if (keycode == KEY_LEFT)
		game->key_left = 1;
	else if (keycode == KEY_DOWN)
		game->key_down = 1;
	else if (keycode == KEY_RIGHT)
		game->key_right = 1;
	return (0);
}

int	key_release(const int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key_w = 0;
	else if (keycode == KEY_A)
		game->key_a = 0;
	else if (keycode == KEY_S)
		game->key_s = 0;
	else if (keycode == KEY_D)
		game->key_d = 0;
	else if (keycode == KEY_UP)
		game->key_up = 0;
	else if (keycode == KEY_LEFT)
		game->key_left = 0;
	else if (keycode == KEY_DOWN)
		game->key_down = 0;
	else if (keycode == KEY_RIGHT)
		game->key_right = 0;
	return (0);
}

int	keyhook(t_game *game)
{
	long		current_time;

	current_time = get_time_ms();
	update_enemies(game);
	if (current_time - game->last_input_time >= 150)
	{
		if (game->key_w || game->key_up)
		{
			game->last_input_time = current_time;
			update_player(game, UP);
		}
		else if (game->key_a || game->key_left)
		{
			game->last_input_time = current_time;
			update_player(game, LEFT);
		}
		else if (game->key_d || game->key_right)
		{
			game->last_input_time = current_time;
			update_player(game, RIGHT);
		}
		else if (game->key_s || game->key_down)
		{
			game->last_input_time = current_time;
			update_player(game, DOWN);
		}
	}
	if (check_enemy_collision(game))
	{
		ft_printf("\r\033[KMoves: %d\nYou died!\n", game->move_count);
		ft_free_exit(game, 0);
	}
	if (current_time - game->player.last_move > 150)
		render_player(game, game->player.x, game->player.y, 1);
	return (0);
}

int	x_keyhook(t_game *game)
{
	ft_printf("\r\033[KMoves: %d\n", game->move_count);
	ft_free_exit(game, 0);
	return (0);
}

void	handle_keys(t_game *game)
{
	game->key_w = 0;
	game->key_a = 0;
	game->key_s = 0;
	game->key_d = 0;
	game->key_up = 0;
	game->key_left = 0;
	game->key_down = 0;
	game->key_right = 0;
	game->last_input_time = 0;
	game->player.last_move = 0;
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_hook(game->win, ClientMessage, LeaveWindowMask, x_keyhook, game);
	mlx_loop_hook(game->mlx, keyhook, game);
}