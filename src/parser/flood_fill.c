/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:47:20 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 16:35:07 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_memory.h"
#include "parser_int.h"

char	**ft_duplicate_map(t_map map)
{
	int		y;
	int		x;
	char	**copy;

	copy = (char **)malloc((map.height + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	y = -1;
	while (++y < map.height)
	{
		copy[y] = (char *)malloc((map.width + 1) * sizeof(char));
		if (!copy[y])
			return (ft_free_partial_matrix((void **)copy, --y), NULL);
		x = -1;
		while (++x < map.width)
			copy[y][x] = map.tiles[y][x].value;
		copy[y][x] = '\0';
	}
	copy[y] = NULL;
	return (copy);
}

static int	r_flood_fill(char **map, int x, int y, t_flood_fill *flood_fill)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '1' || map[y][x] == '\0')
		return (0);
	if (map[y][x] == 'C')
		flood_fill->collectibles--;
	if (map[y][x] == 'E')
	{
		flood_fill->exit_found = 1;
		if (!flood_fill->collectibles)
			return (1);
		return (0);
	}
	map[y][x] = '1';
	if (!flood_fill->collectibles && flood_fill->exit_found)
		return (1);
	if (r_flood_fill(map, x + 1, y, flood_fill)
		|| r_flood_fill(map, x - 1, y, flood_fill)
		|| r_flood_fill(map, x, y + 1, flood_fill)
		|| r_flood_fill(map, x, y - 1, flood_fill))
		return (1);
	return (0);
}

void	flood_fill(t_game *game)
{
	t_flood_fill	flood_fill;
	char			**map_dup;
	int				map_valid;

	map_dup = ft_duplicate_map(game->map);
	if (!map_dup)
		ft_free_exit(game, E_MEMORY_ALLOC);
	flood_fill.collectibles = game->map.collectible_count;
	flood_fill.exit_found = 0;
	map_valid = r_flood_fill(map_dup, game->player.x, game->player.y,
			&flood_fill);
	ft_free_matrix((void **)map_dup);
	if (!map_valid)
		ft_free_exit(game, E_OBSTRUCTED_PATH);
}
