/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:24:46 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/04 22:34:23 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_util.h"
#include <stdlib.h>
#include <sys/time.h>

void	put_tile(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite, x * TILE_SIZE, y
		* TILE_SIZE);
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_msleep(long msec)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < msec)
		;
}

int	is_out_of_bounds(t_game *game, int x, int y)
{
	return (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height);
}
