/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:33:58 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 13:32:07 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "lft_memory.h"
#include "lft_print.h"
#include <mlx.h>
#include <stdlib.h>

static void	init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			(game->map.height + 1) * TILE_SIZE, "so_long");
	game->player.direction = DOWN;
	game->player.is_idle = 1;
	mlx_set_font(game->mlx, game->win, "-*-*-bold-r-*-*-20-*-*-*-*-*-*-*");
}

static int	ft_loop_hook(t_game *game)
{
	long		current_time;

	update_exit_animation(game);
	update_enemies(game);
	if (check_enemy_collision(game))
	{
		ft_printf("\r\033[KMoves: %d\nYou died!\n", game->player.move_count);
		ft_free_exit(game, 0);
	}
	current_time = get_time_ms();
	if (current_time - game->last_input_time >= 120)
		key_loop(game, current_time);
	if (current_time - game->last_input_time >= 150)
	{
		if (!game->player.is_idle)
		{
			game->player.is_idle = 1;
			render_player(game);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_print_error(E_INVALID_FORMAT));
	ft_bzero(&game, sizeof(t_game));
	parse_map(&game, av[1]);
	init(&game);
	load_sprites(&game);
	render_all(&game);
	handle_keys(&game);
	mlx_loop_hook(game.mlx, ft_loop_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
