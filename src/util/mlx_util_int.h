/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util_int.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:27:30 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 15:25:47 by joao-alm         ###   ########.fr       */
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
}			t_blend;

#endif