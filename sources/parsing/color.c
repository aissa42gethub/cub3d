/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 17:04:09 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//returns 1 if read line is floor or ceiling color
bool	is_line_color(char *line)
{
	if (line[0] == 'F' || line[0] == 'C')
		return (1);
	return (0);
}

//parses and stores color info into r, g and b components
static int	parse_rgb(char *rgb, int (*plane)[3])
{
	char	**split;
	int		i;

	split = ft_split(rgb, ',');
	i = 0;
	while (split && split[i])
		i++;
	if (i != 3)
		return (ft_freearray(split), 1);
	(*plane)[0] = ft_atoi(split[0]);
	(*plane)[1] = ft_atoi(split[1]);
	(*plane)[2] = ft_atoi(split[2]);
	if ((*plane)[0] < 0 || (*plane)[0] > 255 || (*plane)[1] < 0
		|| (*plane)[1] > 255 || (*plane)[2] < 0 || (*plane)[2] > 255)
		return (ft_freearray(split), 1);
	return (ft_freearray(split), 0);
}

//handler to get color to ceiling and floor information
bool	handle_color_line(t_cub *cub, char *line)
{
	char	*rgb;
	int		status;

	rgb = ft_strtrim(line + 1, " \t\n");
	if (!rgb)
		return (print_error("Failed ft_strtrim in handle_color_line"));
	if (line[0] == 'F')
		status = parse_rgb(rgb, &cub->bg.floor);
	else
		status = parse_rgb(rgb, &cub->bg.ceiling);
	if (status)
		print_error("Failed color validation");
	free(rgb);
	return (status);
}
