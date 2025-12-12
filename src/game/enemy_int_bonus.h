/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_int_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:38:51 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 17:19:26 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_INT_BONUS_H
# define ENEMY_INT_BONUS_H

# include "so_long.h"

void	move_enemy_horizontal(t_game *game, t_enemy *enemy);
void	move_enemy_vertical(t_game *game, t_enemy *enemy);
int		should_bounce(t_game *game, int x, int y);

#endif