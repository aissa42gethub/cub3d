/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:04:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 16:15:17 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//ensures that all characters in map is valid
static int	validate_map_chars(char **map)
{
	int		x;
	int		y;
	int		pos;
	char	c;

	pos = 0;
	x = 0;
	while (map && map[x])
	{
		y = 0;
		c = map[x][y];
		while (c)
		{
			if (c != 'N' && c != 'S' && c != 'E' && c != 'W'
				&& c != '0' && c != '1' && c != ' ')
				return (print_error("Invalid character in map"));
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				pos++;
			c = map[x][y++];
		}
		x++;
	}
	if (pos != 1)
		return (print_error("Invalid player position in map"));
	return (0);
}

//gets number of valid characters in read line
static int	get_line_width(char **map, int y)
{
	int	idx;
	int	x;

	idx = 0;
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] != ' ')
			idx = x;
		x++;
	}
	return (idx + 1);
}

//stores map's width and height and returns minimum index to valid map point
static int	get_map_dimensions(t_cub *cub)
{
	int	idx;
	int	start;
	int	x;

	idx = 0;
	start = INT_MAX;
	while (cub->map.point[cub->map.h])
	{
		idx = get_line_width(cub->map.point, cub->map.h);
		if (idx > cub->map.w)
			cub->map.w = idx;
		x = 0;
		while (cub->map.point[cub->map.h][x] == ' '
			|| cub->map.point[cub->map.h][x] == '\t')
			x++;
		if (x < start)
			start = x;
		cub->map.h++;
	}
	cub->map.w -= start;
	return (start);
}

//fills in map lines with spaces when line is less than map's width
static int	make_map_rectangular(t_cub *cub, int start)
{
	char	*line;
	int		y;
	int		len;

	y = 0;
	while (y < cub->map.h)
	{
		line = malloc(cub->map.w + 1);
		if (!line)
			return (print_error("Malloc failed in make_map_rectangular"));
		len = get_line_width(cub->map.point, y);
		ft_memset(line, ' ', cub->map.w);
		line[cub->map.w] = '\0';
		ft_memcpy_rng(line, cub->map.point[y], start, len - start);
		free(cub->map.point[y]);
		cub->map.point[y] = line;
		y++;
	}
	return (0);
}

//ensure that map is optimal through validation and adjusting its content
int	validate_map(t_cub *cub)
{
	int	start;

	if (validate_map_chars(cub->map.point))
		return (1);
	start = get_map_dimensions(cub);
	if (make_map_rectangular(cub, start))
		return (1);
	return (0);
}
