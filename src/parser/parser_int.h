/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:58:21 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/25 10:10:46 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INT_H
# define PARSER_INT_H

#include "so_long.h"

typedef struct s_flood_fill
{
	int			collectibles;
	int			exit_found;
}				t_flood_fill;


// validate_map
void					validate_map(t_game *game);

// util
void					ft_init_map(t_game *game);
char					**ft_duplicate_map(char **map);

#endif // MAP_H
