/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:09:36 by joao-alm          #+#    #+#             */
/*   Updated: 2025/11/30 19:05:57 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

enum					e_sprites
{
	PLAYER_UP0,
	PLAYER_UP1,
	PLAYER_UP2,
	PLAYER_LEFT0,
	PLAYER_LEFT1,
	PLAYER_LEFT2,
	PLAYER_RIGHT0,
	PLAYER_RIGHT1,
	PLAYER_RIGHT2,
	PLAYER_DOWN0,
	PLAYER_DOWN1,
	PLAYER_DOWN2,
	PLAYER_CHEST,
	CHEST0,
	CHEST1,
	VOID,
	WALL_V_TOP,
	WALL_V,
	WALL_H_TOP,
	WALL_H,
	FLOOR,
	MAP_EXIT,
	N_SPRITES
};

#endif // SPRITES_H
