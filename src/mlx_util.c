/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:53:20 by joao-alm          #+#    #+#             */
/*   Updated: 2025/12/04 20:59:50 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"


static unsigned int	blend_pixel(unsigned int bg, unsigned int fg, int opacity)
{
	unsigned int	result[3];

	result[0] = (((fg >> 16) & 0xFF) * opacity + ((bg >> 16) & 0xFF)
			* (100 - opacity)) / 100;
	result[1] = (((fg >> 8) & 0xFF) * opacity + ((bg >> 8) & 0xFF)
			* (100 - opacity)) / 100;
	result[2] = ((fg & 0xFF) * opacity + (bg & 0xFF) * (100 - opacity)) / 100;
	return ((result[0] << 16) | (result[1] << 8) | result[2]);
}

static void	blend_pixels(t_blend *b)
{
	int				i;
	unsigned int	bg_px;
	unsigned int	fg_px;

	i = -1;
	while (++i < TILE_SIZE * TILE_SIZE)
	{
		bg_px = *(unsigned int *)(b->bg + i * b->bpp);
		fg_px = *(unsigned int *)(b->fg + i * b->bpp);
		if (fg_px != 0xFF000000 && fg_px != 0x00000000)
			*(unsigned int *)(b->img + i * b->bpp)
				= blend_pixel(bg_px, fg_px, b->opacity);
		else
			*(unsigned int *)(b->img + i * b->bpp) = bg_px;
	}
}

void	*create_blended_image(t_game *game, void *bg, void *fg, int opacity)
{
	void	*img;
	t_blend	b;
	int		info[3];

	img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	b.img = mlx_get_data_addr(img, &info[0], &info[1], &info[2]);
	b.bg = mlx_get_data_addr(bg, &info[0], &info[1], &info[2]);
	b.fg = mlx_get_data_addr(fg, &info[0], &info[1], &info[2]);
	b.bpp = info[0] / 8;
	b.opacity = opacity;
	blend_pixels(&b);
	return (img);
}
