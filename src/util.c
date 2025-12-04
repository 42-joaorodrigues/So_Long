/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:24:46 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/03 18:41:18 by joao-alm         ###   ########.fr       */
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

void	ft_msleep(long msec)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < msec)
		;
}

void	put_tile(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite, x * TILE_SIZE, y
		* TILE_SIZE);
}

void	put_transparent_tile(t_game *game, void *bg, void *fg, int x, int y)
{
	char			*fg_data;
	int				info[3];
	int				px[2];
	unsigned int	pixel;

	mlx_put_image_to_window(game->mlx, game->win, bg, x * TILE_SIZE,
		y * TILE_SIZE);
	fg_data = mlx_get_data_addr(fg, &info[0], &info[1], &info[2]);
	px[1] = -1;
	while (++px[1] < TILE_SIZE)
	{
		px[0] = -1;
		while (++px[0] < TILE_SIZE)
		{
			pixel = *(unsigned int *)(fg_data + px[1] * info[1]
					+ px[0] * (info[0] / 8));
			if (pixel != 0xFF000000 && pixel != 0x00000000)
				mlx_pixel_put(game->mlx, game->win, x * TILE_SIZE + px[0],
					y * TILE_SIZE + px[1], pixel);
		}
	}
}
