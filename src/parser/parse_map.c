/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:36:39 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/02 09:18:51 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_int.h"
#include "lft_gnl.h"
#include "lft_list.h"
#include "lft_string.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	load_map(t_list *map_list, t_map *map)
{
	t_list	*current;
	int		i;

	map->height = ft_lstsize(map_list);
	map->width = 0;
	if (map_list)
		map->width = (int)ft_strlen(map_list->content);
	map->array = (char **)malloc((map->width + 1) * sizeof(char *));
	if (!map->array)
	{
		ft_lstclear(&map_list, free);
		exit(ft_print_error(E_MEMORY_ALLOC));
	}
	current = map_list;
	i = 0;
	while (current)
	{
		map->array[i++] = current->content;
		current = current->next;
	}
	map->array[i] = NULL;
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
}
