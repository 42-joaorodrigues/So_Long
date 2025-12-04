/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:33:58 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/04 23:02:56 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

static void	init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	init_player(game);
	// init_enemies
}

static int	ft_loop_hook(t_game *game)
{
	long		current_time;

	current_time = get_time_ms();
	// update_enemies(game);
	if (current_time - game->last_input_time >= 150)
		key_loop(game, current_time);
	// if (check_enemy_collision(game))
	// {
	// 	ft_printf("\r\033[KMoves: %d\nYou died!\n", game->player.move_count);
	// 	ft_free_exit(game, 0);
	// }
	if (current_time - game->player.last_move_ms >= 150)
		render_player(game, 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_print_error(E_INVALID_FORMAT));
	game.mlx = NULL;
	game.win = NULL;
	parse_map(&game, av[1]);
	init(&game);
	load_sprites(&game);
	render_all(&game);
	handle_keys(&game);
	mlx_loop_hook(game.mlx, ft_loop_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
