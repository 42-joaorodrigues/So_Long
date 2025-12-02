/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:24:46 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/02 10:18:36 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <sys/time.h>
#include <stdlib.h>

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	put_tile(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite, x * TILE_SIZE, y
		* TILE_SIZE);
}
