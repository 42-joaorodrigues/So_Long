/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:27:30 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/04 22:35:22 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTIL_H
# define MLX_UTIL_H

#include "so_long.h"
#include "mlx.h"

typedef struct s_blend
{
	char	*img;
	char	*bg;
	char	*fg;
	int		bpp;
	int		opacity;
}			t_blend;

void		*create_blended_image(t_game *game, void *bg, void *fg,
				int opacity);

#endif