/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aissa <aissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/02 10:23:11 by aissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//ensures file extension is .cub
static bool	check_extension(const char *file)
{
	const char	*ext;
	int			i;
	int			j;

	ext = ".cub";
	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i] == ext[j])
			j++;
		else
			j = 0;
		i++;
	}
	if (j == 4 && !ext[j])
		return (0);
	else
		return (print_error("Invalid file extension. Expected .cub"));
}

//removes space, tabs and newlines from start and end depending on line content
static bool	trim_line(char **line, char *trim)
{
	if (!trim)
		return (1);
	if (is_line_texture(trim) || is_line_color(trim))
	{
		free(*line);
		*line = trim;
	}
	else if (trim[0] != '\0')
	{
		free(trim);
		trim = ft_strtrim(*line, "\t\n");
		if (!trim)
			return (1);
		free(*line);
		*line = trim;
	}
	else
	{
		free(trim);
		free(*line);
		*line = NULL;
	}
	return (0);
}

//parses info appropriately when reading line by line from cub file
static bool	handle_content_loop(t_cub *cub, char **line)
{
	if (trim_line(line, ft_strtrim(*line, " \t\n")))
		return (print_error("Failed ft_strtrim in trim_line"));
	if (!(*line))
		return (0);
	if (is_line_texture(*line))
	{
		if (handle_texture_line(cub, *line))
			return (1);
	}
	else if (is_line_color(*line))
	{
		if (handle_color_line(cub, *line))
			return (1);
	}
	else
		if (append_map_line(cub, *line))
			return (1);
	return (0);
}

//reads and parses every line in cub file, freeing them once complete
static bool	parse_content(t_cub *cub, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (handle_content_loop(cub, &line))
			return (free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}

//extracts .cub file content and validates into the program's struct
bool	parsing(t_cub *cub, char **av)
{
	int	fd;

	if (check_extension(av[1]))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (print_error("Failed to read .cub file"));
	if (parse_content(cub, fd))
		return (close(fd), 1);
	close(fd);
	if (validate_map(cub))
		return (1);
	set_player_values(cub);
	debug_struct(cub);
	if (validate_closed_map(cub, cub->player.y, cub->player.x))
		return (1);
	cub->map.point[(int)(cub->player.y)][(int)(cub->player.x)] = '0';
	debug_map_final(cub->map);
	return (0);
}
