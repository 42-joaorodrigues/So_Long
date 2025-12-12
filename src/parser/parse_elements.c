/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:15:41 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 15:48:21 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_memory.h"
#include "lft_string.h"
#include "parser_int.h"

void	ft_init_map(t_game *game, t_counts *counts)
{
	game->map.collectible_count = 0;
	game->enemies_count = 0;
	counts->players_count = 0;
	counts->exits_count = 0;
}

static void	handle_character(t_game *game, int x, int y, t_counts *counts)
{
	char	*c;

	c = &game->map.tiles[y][x].value;
	if ((x <= 0 || x >= game->map.width - 1 || y <= 0 || y >= game->map.height
			- 1) && *c != '1')
		ft_free_exit(game, E_MAP_NOT_SURROUNDED);
	if (*c == 'P')
	{
		game->player.x = x;
		game->player.y = y;
		counts->players_count++;
		*c = '0';
	}
	else if (*c == 'H' || *c == 'h' || *c == 'V' || *c == 'v')
		parse_enemy(game, x, y, c);
	else if (*c == 'C')
		game->map.collectible_count++;
	else if (*c == 'E')
	{
		game->map.exit_x = x;
		game->map.exit_y = y;
		counts->exits_count++;
	}
	else if (*c != '0' && *c != '1')
		ft_free_exit(game, E_INVALID_CHARACTER);
}

void	parse_elements(t_game *game)
{
	t_counts	counts;
	int			x;
	int			y;

	ft_init_map(game, &counts);
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
			handle_character(game, x, y, &counts);
	}
	if (counts.players_count < 1)
		ft_free_exit(game, E_NO_START);
	if (counts.players_count > 1)
		ft_free_exit(game, E_MULTIPLE_STARTS);
	if (game->map.collectible_count < 1)
		ft_free_exit(game, E_NO_COLLECTIBLE);
	if (counts.exits_count < 1)
		ft_free_exit(game, E_NO_EXIT);
	if (counts.exits_count > 1)
		ft_free_exit(game, E_MULTIPLE_EXITS);
}
