/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissa <aaissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:34:38 by aaissa            #+#    #+#             */
/*   Updated: 2025/10/02 18:31:42 by aaissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_single_tile(t_cub *cub, t_tile *tile, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_TILE_SIZE)
	{
		j = 0;
		while (j < MINIMAP_TILE_SIZE)
		{
			if (i == 0 || j == 0 || i == tile - 1 || j == tile - 1)
				my_pixel_put(&cub->mlx, tile->psx + j, tile->psy + i, 0x444444);
			else
				my_pixel_put(&cub->mlx, tile->psx + j, tile->psy + i, color);
			j++;
		}
		i++;
	}
}

void	choose_color(t_cub *cub, int *color, t_tile *tile)
{
	if (cub->map.point[tile->my][tile->mx] == '1')
		*color = 0x0000FF;
	else
		*color = 0x000000;
}

void	which_tile(t_cub *cub, t_tile *tile)
{
	int	color;

	color = 0;
	if (tile->mx >= 0 && tile->mx < cub->map.w
		&& tile->my >= 0 && tile->my < cub->map.h)
	{
		choose_color(cub, &color, tile);
		render_single_tile(cub, tile, color);
	}
	else
		render_single_tile(cub, tile, 0x444444);
}

static void	render_tiles(t_cub *cub, int px, int py)
{
	t_tile	tile;
	int		j;
	int		i;

	i = -MINIMAP_SIZE / 2;
	while (i < MINIMAP_SIZE / 2)
	{
		j = -MINIMAP_SIZE / 2;
		while (j < MINIMAP_SIZE / 2)
		{
			tile.mx = px + j;
			tile.my = py + i;
			tile.psx = MINIMAP_OFFSET + (j + MINIMAP_SIZE / 2)
				* MINIMAP_TILE_SIZE;
			tile.psy = MINIMAP_OFFSET + (i + MINIMAP_SIZE / 2)
				* MINIMAP_TILE_SIZE;
			which_tile(cub, &tile);
			j++;
		}
		i++;
	}
}

void	render_2d_map(t_cub *cub)
{
	int	px;
	int	py;

	px = (int)cub->player.x;
	py = (int)cub->player.y;
	render_tiles(cub, px, py);
	render_player_and_fov(cub);
}
