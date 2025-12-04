/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:36:39 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/04 18:47:53 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_gnl.h"
#include "lft_list.h"
#include "lft_memory.h"
#include "lft_string.h"
#include "parser_int.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	parse_map_line(t_map *map, int line_idx, char *map_line)
{
	int	i;

	if (ft_strlen(map_line) != map->width)
	{
		ft_free_partial_matrix(map->tiles, --line_idx);
		ft_print_error(E_MAP_NOT_RECTANGLE);
		return (-1);
	}
	map->tiles[line_idx] = (t_tile *)malloc(map->width * sizeof(t_tile));
	if (!map->tiles[line_idx])
	{
		ft_free_partial_matrix(map->tiles, --line_idx);
		ft_print_error(E_MEMORY_ALLOC);
		return (-1);
	}
	i = -1;
	while (++i < map->width)
		map->tiles[line_idx][i].value = map_line[i];
	return (0);
}

static void	load_map(t_list *map_list, t_map *map)
{
	t_list	*current;
	int		i;

	map->height = ft_lstsize(map_list);
	map->width = 0;
	if (map_list)
		map->width = (int)ft_strlen(map_list->content);
	map->tiles = (t_tile **)malloc((map->height) * sizeof(t_tile *));
	if (!map->tiles)
	{
		ft_lstclear(&map_list, free);
		exit(ft_print_error(E_MEMORY_ALLOC));
	}
	current = map_list;
	i = 0;
	while (current)
	{
		if (parse_map_line(map, i++, current->content) != 0)
		{
			ft_lstclear(&map_list, free);
			exit(1);
		}
		current = current->next;
	}
	ft_lstclear(&map_list, NULL);
}

static t_list	*read_map(const char *filename)
{
	t_list	*map_list;
	int		fd;
	char	*line;

	map_list = NULL;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&map_list, ft_lstnew(ft_strtrim(line, "\n")));
		free(line);
	}
	close(fd);
	return (map_list);
}

static void	validate_map_file(const char *filename)
{
	int		fd;
	size_t	len;

	fd = open(filename, O_RDONLY);
	close(fd);
	if (fd < 0)
		exit(ft_print_error(E_INVALID_FD));
	len = ft_strlen(filename);
	if (len <= 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		exit(ft_print_error(E_INVALID_TYPE));
}

void	parse_map(t_game *game, const char *filename)
{
	t_list	*map_list;

	validate_map_file(filename);
	map_list = read_map(filename);
	load_map(map_list, &game->map);
	validate_map(game);
	flood_fill(game);
	mark_void_walls(game);
	set_sprite_ids(game);
}
