/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 00:17:01 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//extracts map line by line from cub file
int	append_map_line(t_cub *cub, char *line)
{
	char	**map;
	int		count;
	int		i;

	count = 0;
	while (cub->map.point && cub->map.point[count])
		count++;
	map = malloc(sizeof(char *) * (count + 2));
	if (!map)
		return (print_error("Failed malloc in append_map_line"));
	i = -1;
	while (++i < count)
		map[i] = cub->map.point[i];
	map[count] = ft_strdup(line);
	if (!map[count])
		return (print_error("Failed ft_strdup in append_map_line"));
	map[count + 1] = NULL;
	free(cub->map.point);
	cub->map.point = map;
	return (0);
}
