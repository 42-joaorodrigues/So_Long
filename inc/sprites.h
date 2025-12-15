/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:09:36 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/13 17:07:52 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

enum	e_sprites
{
	PLAYER_IDLE_UP,
	PLAYER_WALK_UP_0,
	PLAYER_WALK_UP_1,
	PLAYER_IDLE_LEFT,
	PLAYER_WALK_LEFT_0,
	PLAYER_WALK_LEFT_1,
	PLAYER_IDLE_RIGHT,
	PLAYER_WALK_RIGHT_0,
	PLAYER_WALK_RIGHT_1,
	PLAYER_IDLE_DOWN,
	PLAYER_WALK_DOWN_0,
	PLAYER_WALK_DOWN_1,
	PLAYER_OPEN_CHEST,
	WALL_VERTICAL_TOP,
	WALL_VERTICAL,
	WALL_HORIZONTAL_TOP,
	WALL_HORIZONTAL,
	CHEST_OPEN,
	CHEST_CLOSE,
	FLOOR,
	VOID,
	EXIT_OPEN_0,
	EXIT_OPEN_1,
	ENEMY_WALK_UP_0,
	ENEMY_WALK_UP_1,
	ENEMY_WALK_LEFT_0,
	ENEMY_WALK_LEFT_1,
	ENEMY_WALK_RIGHT_0,
	ENEMY_WALK_RIGHT_1,
	ENEMY_WALK_DOWN_0,
	ENEMY_WALK_DOWN_1,
	N_SPRITES
};

#endif // SPRITES_H
