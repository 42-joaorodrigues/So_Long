/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:33:58 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/03 16:45:15 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_print_error(E_INVALID_FORMAT));
	parse_map(&game, av[1]);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * TILE_SIZE,
			game.map.height * TILE_SIZE, "so_long");
	render_map(&game);
	game.move_count = 0;
	handle_keys(&game);
	game.player.last_move = 0;
	mlx_loop(game.mlx);
	return (0);
}
