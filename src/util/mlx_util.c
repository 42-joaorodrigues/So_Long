/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:53:20 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/12 15:26:56 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util_int.h"

static void	overlay_pixels(t_blend *data)
{
	int				i;
	unsigned int	*img_px;
	unsigned int	*bg_px;
	unsigned int	*fg_px;

	i = -1;
	while (++i < TILE_SIZE * TILE_SIZE)
	{
		img_px = (unsigned int *)(data->img + i * data->bpp);
		bg_px = (unsigned int *)(data->bg + i * data->bpp);
		fg_px = (unsigned int *)(data->fg + i * data->bpp);
		if (*fg_px != 0xFF000000 && *fg_px != 0x00000000)
			*img_px = *fg_px;
		else
			*img_px = *bg_px;
	}
}

void	*create_blended_image(t_game *game, void *bg, void *fg)
{
	void		*img;
	t_blend		data;
	int			info[3];

	img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	data.img = mlx_get_data_addr(img, &info[0], &info[1], &info[2]);
	data.bg = mlx_get_data_addr(bg, &info[0], &info[1], &info[2]);
	data.fg = mlx_get_data_addr(fg, &info[0], &info[1], &info[2]);
	data.bpp = info[0] / 8;
	overlay_pixels(&data);
	return (img);
}
