/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:49:28 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/30 18:59:50 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_INT_H
# define RENDER_INT_H

#include "so_long.h"

// Sprites
void	load_sprites(t_game *game);

// Void Walls
void	mark_void_walls(t_game *game);

#endif