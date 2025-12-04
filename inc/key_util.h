/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:09:36 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/04 21:05:08 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_UTIL_H
# define KEY_UTIL_H

enum	e_keycodes
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_UP = 65362,
	KEY_LEFT = 65361,
	KEY_DOWN = 65364,
	KEY_RIGHT = 65363
};

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	up;
	int	left;
	int	down;
	int	right;
}		t_keys;

#endif // KEY_UTIL_H
