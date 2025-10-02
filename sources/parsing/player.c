/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:04:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 00:37:05 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//set player position and direction
void	set_player_values(t_cub *cub)
{
	int		x;
	int		y;

	x = 0;
	while (cub->map.point && cub->map.point[x])
	{
		y = 0;
		while (cub->map.point[x][y])
		{
			if (cub->map.point[x][y] == 'N' || cub->map.point[x][y] == 'S'
				|| cub->map.point[x][y] == 'E' || cub->map.point[x][y] == 'W')
			{
				cub->player.y = x;
				cub->player.x = y;
				cub->player.dir = cub->map.point[x][y];
				return ;
			}
			y++;
		}
		x++;
	}
}
