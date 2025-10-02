/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 16:16:51 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//recursive flood fill algorithm to test for map validity
static bool	flood_fill(t_map *map, char **copy, int y, int x)
{
	if ((*map).is_invalid)
		return (1);
	if (y < 0 || y >= (*map).h || x < 0 || x >= (*map).w || copy[y][x] == ' ')
	{
		(*map).is_invalid = 1;
		return (print_error("Map failed floodfill test"));
	}
	if (copy[y][x] == '1' || copy[y][x] == '.')
		return (0);
	copy[y][x] = '.';
	flood_fill(map, copy, y + 1, x);
	flood_fill(map, copy, y - 1, x);
	flood_fill(map, copy, y, x + 1);
	flood_fill(map, copy, y, x - 1);
	return (0);
}

//make a deep copy of map
static bool	copy_map_for_floodfill(t_map map, char ***copy)
{
	int	y;

	*copy = malloc(sizeof(char *) * (map.h + 1));
	if (!(*copy))
		return (print_error("Malloc failed in copy_map_for_floodfill"));
	y = 0;
	while (y < map.h)
	{
		(*copy)[y] = ft_strdup(map.point[y]);
		if (!(*copy)[y++])
		{
			ft_freearray(*copy);
			return (print_error("Failed ft_strdup in copy_map_for_floodfill"));
		}
	}
	(*copy)[y] = NULL;
	return (0);
}

bool	validate_closed_map(t_cub *cub, int y, int x)
{
	char	**copy;

	if (copy_map_for_floodfill(cub->map, &copy))
		return (1);
	flood_fill(&cub->map, copy, y, x);
	debug_map_floodfill(copy, cub->map.is_invalid);
	return (ft_freearray(copy), cub->map.is_invalid);
}
