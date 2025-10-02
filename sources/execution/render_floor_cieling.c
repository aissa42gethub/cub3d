/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_cieling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissa <aaissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:21:12 by aaissa            #+#    #+#             */
/*   Updated: 2025/10/02 16:27:12 by aaissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_move(int x, int y, t_cub *cub)
{
	int	delta_x;
	int	mouse_x;

	(void)y;
	mouse_x = cub->player.mouse_x;
	if (mouse_x == -1)
		mouse_x = x;
	delta_x = x - mouse_x;
	if (delta_x > 0)
		rotate_player(cub, RARROW);
	else if (delta_x < 0)
		rotate_player(cub, LARROW);
	cub->player.mouse_x = x;
	return (0);
}

void	my_pixel_put(t_mlx *img, int x, int y, int color)
{
	char	*pixel_addr;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel_addr = img->addr + (y * img->line_length + x
			* (img->bits_per_pixel / 8));
	*(unsigned int *)pixel_addr = color;
}

static int	rgb_to_int(int rgb[3])
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	render_ceiling_floor(t_cub *cub, int start, int end, int color)
{
	int	x;

	while (start < end)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_pixel_put(&cub->mlx, x, start, color);
			x++;
		}
		start++;
	}
}

void	render_background(t_cub *cub)
{
	int	ceiling_color;
	int	floor_color;

	ceiling_color = rgb_to_int(cub->bg.ceiling);
	floor_color = rgb_to_int(cub->bg.floor);
	render_ceiling_floor(cub, 0, WIN_HEIGHT / 2, ceiling_color);
	render_ceiling_floor(cub, WIN_HEIGHT / 2, WIN_HEIGHT, floor_color);
}
