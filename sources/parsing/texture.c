/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 15:36:26 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//returns 1 if read line is north, south, west or east texture
bool	is_line_texture(char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		return (1);
	return (0);
}

//extracts and stores path to texture file
static bool	assign_texture(char **dest, char *line)
{
	char	*path;

	path = ft_strtrim(line + 2, " \t\n");
	if (!path)
		return (print_error("Failed ft_strtrim in assign_texture"));
	*dest = path;
	return (0);
}

//handler to get texture information
bool	handle_texture_line(t_cub *cub, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (assign_texture(&cub->tex.no, line));
	else if (!ft_strncmp(line, "SO", 2))
		return (assign_texture(&cub->tex.so, line));
	else if (!ft_strncmp(line, "WE", 2))
		return (assign_texture(&cub->tex.we, line));
	else if (!ft_strncmp(line, "EA", 2))
		return (assign_texture(&cub->tex.ea, line));
	return (1);
}
